begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===------ abi.h - configuration header for compiler-rt  -----------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file is a configuration header for compiler-rt.  * This file is not part of the interface of this library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_if
if|#
directive|if
name|__ARM_EABI__
end_if

begin_define
define|#
directive|define
name|ARM_EABI_FNALIAS
parameter_list|(
name|aeabi_name
parameter_list|,
name|name
parameter_list|)
define|\
value|void __aeabi_##aeabi_name() __attribute__((alias("__" #name)));
end_define

begin_define
define|#
directive|define
name|COMPILER_RT_ABI
value|__attribute__((pcs("aapcs")))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARM_EABI_FNALIAS
parameter_list|(
name|aeabi_name
parameter_list|,
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|COMPILER_RT_ABI
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

