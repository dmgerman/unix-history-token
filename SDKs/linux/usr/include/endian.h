begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- endian.h - stub SDK header for compiler-rt -------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===-----------------------------------------------------------------------===  *  * This is a stub SDK header file. This file is not part of the interface of  * this library nor an official version of the appropriate SDK header. It is  * intended only to stub the features of this header required by compiler-rt.  *  * ===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ENDIAN_H__
end_ifndef

begin_define
define|#
directive|define
name|__ENDIAN_H__
end_define

begin_define
define|#
directive|define
name|__LITTLE_ENDIAN
value|1234
end_define

begin_define
define|#
directive|define
name|__BIG_ENDIAN
value|4321
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__LITTLE_ENDIAN__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ORDER_LITTLE_ENDIAN__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__BYTE_ORDER
value|__LITTLE_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__BYTE_ORDER
value|__BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ENDIAN_H__ */
end_comment

end_unit

