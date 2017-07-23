begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_tls_get_addr.h --------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Handle the __tls_get_addr call.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// All this magic is specific to glibc and is required to workaround
end_comment

begin_comment
comment|// the lack of interface that would tell us about the Dynamic TLS (DTLS).
end_comment

begin_comment
comment|// https://sourceware.org/bugzilla/show_bug.cgi?id=16291
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The matters get worse because the glibc implementation changed between
end_comment

begin_comment
comment|// 2.18 and 2.19:
end_comment

begin_comment
comment|// https://groups.google.com/forum/#!topic/address-sanitizer/BfwYD8HMxTM
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Before 2.19, every DTLS chunk is allocated with __libc_memalign,
end_comment

begin_comment
comment|// which we intercept and thus know where is the DTLS.
end_comment

begin_comment
comment|// Since 2.19, DTLS chunks are allocated with __signal_safe_memalign,
end_comment

begin_comment
comment|// which is an internal function that wraps a mmap call, neither of which
end_comment

begin_comment
comment|// we can intercept. Luckily, __signal_safe_memalign has a simple parseable
end_comment

begin_comment
comment|// header which we can use.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_TLS_GET_ADDR_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_TLS_GET_ADDR_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
struct|struct
name|DTLS
block|{
comment|// Array of DTLS chunks for the current Thread.
comment|// If beg == 0, the chunk is unused.
struct|struct
name|DTV
block|{
name|uptr
name|beg
decl_stmt|,
name|size
decl_stmt|;
block|}
struct|;
name|uptr
name|dtv_size
decl_stmt|;
name|DTV
modifier|*
name|dtv
decl_stmt|;
comment|// dtv_size elements, allocated by MmapOrDie.
comment|// Auxiliary fields, don't access them outside sanitizer_tls_get_addr.cc
name|uptr
name|last_memalign_size
decl_stmt|;
name|uptr
name|last_memalign_ptr
decl_stmt|;
block|}
struct|;
comment|// Returns pointer and size of a linker-allocated TLS block.
comment|// Each block is returned exactly once.
name|DTLS
operator|::
name|DTV
operator|*
name|DTLS_on_tls_get_addr
argument_list|(
argument|void *arg
argument_list|,
argument|void *res
argument_list|,
argument|uptr static_tls_begin
argument_list|,
argument|uptr static_tls_end
argument_list|)
expr_stmt|;
name|void
name|DTLS_on_libc_memalign
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|uptr
name|size
parameter_list|)
function_decl|;
name|DTLS
modifier|*
name|DTLS_Get
parameter_list|()
function_decl|;
name|void
name|DTLS_Destroy
parameter_list|()
function_decl|;
comment|// Make sure to call this before the thread is destroyed.
comment|// Returns true if DTLS of suspended thread is in destruction process.
name|bool
name|DTLSInDestruction
parameter_list|(
name|DTLS
modifier|*
name|dtls
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_TLS_GET_ADDR_H
end_comment

end_unit

