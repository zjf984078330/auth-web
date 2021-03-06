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

#include "domainhelper.h"

using namespace auth::helpers;

Object auth::helpers::DomainHelper::toJson(const Domain::Ptr &domain) noexcept
{
    Object ret;
    ret.set(Domain::FIELD_ID, domain->id);
    ret.set(Domain::FIELD_NAME, domain->name);
    ret.set(Domain::FIELD_STATUS, static_cast<uint8_t>(domain->status));
    ret.set(Domain::FIELD_EXPIRATION_DATE, domain->expirationDate);
    ret.set(Domain::FIELD_EXPIRATION_JWT, domain->expirationJWT);
    return ret;
}
