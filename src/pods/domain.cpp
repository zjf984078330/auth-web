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

#include "domain.h"

#include <Poco/JSON/Object.h>
using Poco::JSON::Object;

using namespace auth::pods;

//inline Object Domain::toDocument() const noexcept
//{

//    Object object;

//    return object;


////    return Object()
////            .add(FIELD_ID, id)
////            .add(FIELD_NAME, name)
////            .add(FIELD_SEECRET, seecret)
////            .add(FIELD_STATUS, static_cast<int>(status))
////            .add(FIELD_EXPIRATION_DATE, expirationDate);
//}

//void Domain::deserialize(const result_set *rs)
//{
//    //id = rs->get_signed64(FIELD_ID);
//    name = rs->get_string(FIELD_NAME);
//    seecret = rs->get_string(FIELD_SEECRET);
//    status = static_cast<Status>(rs->get_unsigned8(FIELD_STATUS));
//    expirationDate = rs->get_string(FIELD_EXPIRATION_DATE);
//}
