/*
  Copyright 2014 DataStax

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#ifndef __CASS_REQUEST_HPP_INCLUDED__
#define __CASS_REQUEST_HPP_INCLUDED__

#include "buffer.hpp"
#include "macros.hpp"
#include "ref_counted.h"

namespace cass {

class RequestMessage;

class Request : public RefCounted<Request> {
public:
  enum {
    ENCODE_ERROR_UNSUPPORTED_PROTOCOL = -1
  };

  Request(uint8_t opcode)
      : opcode_(opcode) {}

  virtual ~Request() {}

  uint8_t opcode() const { return opcode_; }

  BufferVec* encode(int version, int flags, int stream) const;

protected:
  virtual int encode(int version, BufferVec* bufs) const = 0;

private:
  uint8_t opcode_;

private:
  DISALLOW_COPY_AND_ASSIGN(Request);
};

} // namespace cass

#endif
