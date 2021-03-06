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

#pragma once

#include <memory>
#include <string>
using namespace std;

namespace Poco::JSON
{
class Object;
}
using Poco::JSON::Object;

namespace auth::pods
{

/**
 * @brief The Domain struct data rappresentation of Domain
 * @author Antonio Salsi
 */
struct Domain final
{

    static inline constexpr const char *FIELD_ID = "id";
    static inline constexpr const char *FIELD_NAME = "domain_name";
    static inline constexpr const char *FIELD_SECRET = "domain_secret";
    static inline constexpr const char *FIELD_STATUS = "domain_status";
    static inline constexpr const char *FIELD_EXPIRATION_DATE = "domain_expiration_date";
    static inline constexpr const char *FIELD_EXPIRATION_JWT = "domain_expiration_jwt";
    static inline constexpr const char *SENDER = "domain_sender";

    /**
     * @brief SPDomain shared pointer of Domain
     */
    typedef shared_ptr<Domain> Ptr;

    /**
     * @brief The Status enum status of Domain
     */
    enum class Status : u_int8_t {
        UNACTIVE = 0,
        ACTIVE = 1,
        LOCK = 2
    };

    /**
     * @brief id PK
     */
    uint32_t id;

    /**
     * @brief domain name
     */
    string name;

    /**
     * @brief seecret password for JWT
     */
    string secret;

    /**
     * @brief last login date,
     * @details if nullptr never loged in
     */
    Status status;

    /**
     * @brief expiration date permit to all user of domain the login
     * @details if nullptr the feature i disable
     */
    string expirationDate;

    /**
     * @brief expiration JWT in millis after this date the token expire
     * @details if nullptr the feature i disable
     */
    uint32_t expirationJWT;

    inline Domain(
            uint32_t id,
            string name,
            string seecret,
            Status status,
            string expirationDate,
            uint32_t expirationJWT
            ) :
        id(move(id)),
        name(move(name)),
        secret(move(seecret)),
        status(move(status)),
        expirationDate(move(expirationDate)),
        expirationJWT(move(expirationJWT))
    {}

    Object toObject();

};

}
