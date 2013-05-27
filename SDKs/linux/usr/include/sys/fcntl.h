begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- fcntl.h - stub SDK header for compiler-rt --------------------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===-----------------------------------------------------------------------===  *  * This is a stub SDK header file. This file is not part of the interface of  * this library nor an official version of the appropriate SDK header. It is  * intended only to stub the features of this header required by compiler-rt.  *  * ===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_FCNTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FCNTL_H_
end_define

begin_define
define|#
directive|define
name|O_RDONLY
value|0x0000
end_define

begin_define
define|#
directive|define
name|O_WRONLY
value|0x0001
end_define

begin_define
define|#
directive|define
name|O_RDWR
value|0x0002
end_define

begin_define
define|#
directive|define
name|O_ACCMODE
value|0x0003
end_define

begin_define
define|#
directive|define
name|O_CREAT
value|0x0200
end_define

begin_function_decl
name|int
name|open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_FCNTL_H_ */
end_comment

end_unit

