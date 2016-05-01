/**
 * Copyright (c) 2013-2016, The Kovri I2P Router Project
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 *    conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 *    of conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be
 *    used to endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Parts of the project are originally copyright (c) 2013-2015 The PurpleI2P Project
 */

#ifndef SRC_CORE_CRYPTO_TUNNEL_H_
#define SRC_CORE_CRYPTO_TUNNEL_H_

#include <cstdint>
#include <memory>

#include "AES.h"

namespace i2p {
namespace crypto {

/// @class TunnelEncryption
class TunnelEncryption {  // with double IV encryption
 public:
  TunnelEncryption();
  ~TunnelEncryption();

  void SetKeys(
      const AESKey& layerKey,
      const AESKey& iv_key);

  void Encrypt(
      const std::uint8_t* in,
      std::uint8_t* out);  // 1024 bytes (16 IV + 1008 data)

 private:
  class TunnelEncryptionImpl;
  std::unique_ptr<TunnelEncryptionImpl> m_TunnelEncryptionPimpl;
};

/// @class TunnelDecryption
class TunnelDecryption {  // with double IV encryption
 public:
  TunnelDecryption();
  ~TunnelDecryption();

  void SetKeys(
      const AESKey& layerKey,
      const AESKey& iv_key);

  void Decrypt(
      const std::uint8_t* in,
      std::uint8_t* out);  // 1024 bytes (16 IV + 1008 data)

 private:
  class TunnelDecryptionImpl;
  std::unique_ptr<TunnelDecryptionImpl> m_TunnelDecryptionPimpl;
};

}  // namespace crypto
}  // namespace i2p

#endif  // SRC_CORE_CRYPTO_TUNNEL_H_
