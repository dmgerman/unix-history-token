begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    xxHash - Extremely Fast Hash algorithm    Header File    Copyright (C) 2012-2016, Yann Collet.     BSD 2-Clause License (http://www.opensource.org/licenses/bsd-license.php)     Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are    met:         * Redistributions of source code must retain the above copyright    notice, this list of conditions and the following disclaimer.        * Redistributions in binary form must reproduce the above    copyright notice, this list of conditions and the following disclaimer    in the documentation and/or other materials provided with the    distribution.     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR    A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT    OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY    THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.     You can contact the author at :    - xxHash source repository : https://github.com/Cyan4973/xxHash */
end_comment

begin_comment
comment|/* based on revision d2df04efcbef7d7f6886d345861e5dfda4edacc1 Removed  * everything but a simple interface for computing XXh64. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_XXHASH_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_XXHASH_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|uint64_t
name|xxHash64
argument_list|(
name|llvm
operator|::
name|StringRef
name|Data
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

