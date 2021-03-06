// MIT License
//
// Copyright (c) 2020 Antonio Salsi
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "domaindao.h"

#include <mariadb++/exceptions.hpp>

using namespace auth::daos;

Domain::Ptr DomainDAO::deserialize(const result_set_ref &rs, const string &fieldPrefix) const
{
    return make_shared<Domain>(
                rs->get_unsigned32(fieldPrefix + Domain::FIELD_ID),
                rs->get_string(fieldPrefix + Domain::FIELD_NAME),
                rs->get_string(fieldPrefix + Domain::FIELD_SECRET),
                static_cast<Domain::Status>(rs->get_unsigned8(fieldPrefix + Domain::FIELD_STATUS)),
                rs->get_string(fieldPrefix + Domain::FIELD_EXPIRATION_DATE),
                rs->get_unsigned32(fieldPrefix + Domain::FIELD_EXPIRATION_JWT)
                );
}

void DomainDAO::insert(const Domain::Ptr &domain) const
{
    string query("INSERT INTO domains (");
           query += Domain::FIELD_NAME;
           query += ", ";
           query += Domain::FIELD_SECRET;
           query += ", ";
           query += Domain::FIELD_STATUS;
           query += ", ";
           query += Domain::FIELD_EXPIRATION_DATE;
           query += ", ";
           query += Domain::FIELD_EXPIRATION_JWT;
           query += ") values (?, ?, ?, ?, ?) ";

           AUTH_GLOBAL_LOG(DBG, query);

    statement_ref stmt = connection->create_statement(query);
    stmt->set_string(0, domain->name);
    stmt->set_string(1, domain->secret);
    stmt->set_unsigned8(2, static_cast<uint8_t>(domain->status));
    stmt->set_string(3, domain->expirationDate);
    stmt->set_unsigned32(4, domain->expirationJWT);
    stmt->insert();
}

void DomainDAO::update(const Domain::Ptr &domain) const
{
    string query("UPDATE domains SET ");
            query += Domain::FIELD_NAME;
            query += " = ?, ";
            query += Domain::FIELD_SECRET;
            query += " = ?, ";
            query += Domain::FIELD_STATUS;
            query += " = ?, ";
            query += Domain::FIELD_EXPIRATION_DATE;
            query += " = ?, ";
            query += Domain::FIELD_EXPIRATION_JWT;
            query += " = ? ";
            query += " WHERE id = ?";

           AUTH_GLOBAL_LOG(DBG, query);

    string permissions;

    statement_ref stmt = connection->create_statement(query);
    stmt->set_string(0, domain->name);
    stmt->set_string(1, domain->secret);
    stmt->set_unsigned8(2, static_cast<uint8_t>(domain->status));
    stmt->set_string(3, domain->expirationDate);
    stmt->set_unsigned32(4, domain->expirationJWT);
    stmt->set_unsigned32(5, domain->id);
    stmt->insert();
}

Domain::Ptr DomainDAO::get(const string &name) const
{
    Domain::Ptr ret = nullptr;

    string query = "SELECT * FROM domains "
                   "WHERE domain_name = ? ";

    AUTH_GLOBAL_LOG(DBG, query);

    auto &&stm = connection->create_statement(query);
    stm->set_string(0, name);

    auto &&rs = stm->query();
    if (rs->next())
    {
        ret = deserialize(rs);
    }

    return ret;
}

u64 DomainDAO::del(const string &name) const
{
    string query = "DELETE FROM " + table + " WHERE " + Domain::FIELD_NAME + " = ? ";
    AUTH_GLOBAL_LOG(DBG, query);
    statement_ref stmt = connection->create_statement(query);
    stmt->set_string(0, name);
    return stmt->execute();
}

Domain::Ptr DomainDAO::getLast() const
{
    Domain::Ptr ret = nullptr;

    string query = "SELECT * FROM domains ORDER BY id DESC";

    AUTH_GLOBAL_LOG(DBG, query);

    auto &&stm = connection->create_statement(query);

    auto &&rs = stm->query();
    if (rs->next())
    {
        ret = deserialize(rs);
    }

    return ret;
}
