begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- UuidCompatibility.h -------------------------------------*- C++ -*-===//
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
comment|// Include this header if your system does not have a definition of uuid_t
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|utility_UUID_COMPATIBILITY_H
end_ifndef

begin_define
define|#
directive|define
name|utility_UUID_COMPATIBILITY_H
end_define

begin_comment
comment|// uuid_t is guaranteed to always be a 16-byte array
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uuid_t
index|[
literal|16
index|]
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// utility_UUID_COMPATIBILITY_H
end_comment

end_unit

