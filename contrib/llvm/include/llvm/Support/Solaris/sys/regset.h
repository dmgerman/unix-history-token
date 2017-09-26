begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===- llvm/Support/Solaris/sys/regset.h ------------------------*- C++ -*-===*  *  *                     The LLVM Compiler Infrastructure  *  * This file is distributed under the University of Illinois Open Source  * License. See LICENSE.TXT for details.  *  *===----------------------------------------------------------------------===*  *  * This file works around excessive name space pollution from the system header  * on Solaris hosts.  *  *===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_SOLARIS_SYS_REGSET_H
end_ifndef

begin_empty
empty|#include_next<sys/regset.h>
end_empty

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

