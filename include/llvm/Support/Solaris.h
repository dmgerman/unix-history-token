begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===- llvm/Support/Solaris.h ------------------------------------*- C++ -*-===*  *  *                     The LLVM Compiler Infrastructure  *  * This file is distributed under the University of Illinois Open Source  * License. See LICENSE.TXT for details.  *  *===----------------------------------------------------------------------===*  *  * This file contains portability fixes for Solaris hosts.  *  *===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_SOLARIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_SOLARIS_H
end_define

begin_include
include|#
directive|include
file|<sys/regset.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* Solaris doesn't have endian.h. SPARC is the only supported big-endian ISA. */
end_comment

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sparc
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc__
argument_list|)
end_if

begin_define
define|#
directive|define
name|BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|CS
end_undef

begin_undef
undef|#
directive|undef
name|DS
end_undef

begin_undef
undef|#
directive|undef
name|ES
end_undef

begin_undef
undef|#
directive|undef
name|FS
end_undef

begin_undef
undef|#
directive|undef
name|GS
end_undef

begin_undef
undef|#
directive|undef
name|SS
end_undef

begin_undef
undef|#
directive|undef
name|EAX
end_undef

begin_undef
undef|#
directive|undef
name|ECX
end_undef

begin_undef
undef|#
directive|undef
name|EDX
end_undef

begin_undef
undef|#
directive|undef
name|EBX
end_undef

begin_undef
undef|#
directive|undef
name|ESP
end_undef

begin_undef
undef|#
directive|undef
name|EBP
end_undef

begin_undef
undef|#
directive|undef
name|ESI
end_undef

begin_undef
undef|#
directive|undef
name|EDI
end_undef

begin_undef
undef|#
directive|undef
name|EIP
end_undef

begin_undef
undef|#
directive|undef
name|UESP
end_undef

begin_undef
undef|#
directive|undef
name|EFL
end_undef

begin_undef
undef|#
directive|undef
name|ERR
end_undef

begin_undef
undef|#
directive|undef
name|TRAPNO
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

