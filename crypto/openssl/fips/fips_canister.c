begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ====================================================================  * Copyright (c) 2005 The OpenSSL Project. Rights for redistribution  * and usage in source and binary forms are granted according to the  * OpenSSL license.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__DECC
argument_list|)
end_if

begin_include
include|#
directive|include
file|<c_asm.h>
end_include

begin_pragma
pragma|#
directive|pragma
name|__nostandard
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"e_os.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|POINTER_TO_FUNCTION_IS_POINTER_TO_1ST_INSTRUCTION
argument_list|)
end_if

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__sun
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__sparc
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparcv9
argument_list|)
operator|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__sgi
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__mips
argument_list|)
operator|||
name|defined
argument_list|(
name|mips
argument_list|)
operator|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__osf__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__alpha
argument_list|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__linux
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__arm
argument_list|)
operator|||
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__x86_64
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|__vax__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|POINTER_TO_FUNCTION_IS_POINTER_TO_1ST_INSTRUCTION
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__xlC__
argument_list|)
operator|&&
name|__xlC__
operator|>=
literal|0x600
operator|&&
operator|(
name|defined
argument_list|(
name|_POWER
argument_list|)
operator|||
name|defined
argument_list|(
name|_ARCH_PPC
argument_list|)
operator|)
end_if

begin_function_decl
specifier|static
name|void
modifier|*
name|instruction_pointer_xlc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_pragma
pragma|#
directive|pragma
name|mc_func
name|instruction_pointer_xlc
name|{
pragma|\
literal|"7c0802a6"
comment|/* mflr	r0  */
pragma|\
literal|"48000005"
comment|/* bl	$+4 */
pragma|\
literal|"7c6802a6"
comment|/* mflr	r3  */
pragma|\
literal|"7c0803a6"
comment|/* mtlr	r0  */
name|}
end_pragma

begin_pragma
pragma|#
directive|pragma
name|reg_killed_by
name|instruction_pointer_xlc
name|gr0
name|gr3
end_pragma

begin_define
define|#
directive|define
name|INSTRUCTION_POINTER_IMPLEMENTED
parameter_list|(
name|ret
parameter_list|)
value|(ret=instruction_pointer_xlc());
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FIPS_START
end_ifdef

begin_define
define|#
directive|define
name|FIPS_ref_point
value|FIPS_text_start
end_define

begin_comment
comment|/* Some compilers put string literals into a separate segment. As we  * are mostly interested to hash AES tables in .rodata, we declare  * reference points accordingly. In case you wonder, the values are  * big-endian encoded variable names, just to prevent these arrays  * from being merged by linker. */
end_comment

begin_decl_stmt
specifier|const
name|unsigned
name|int
name|FIPS_rodata_start
index|[]
init|=
block|{
literal|0x46495053
block|,
literal|0x5f726f64
block|,
literal|0x6174615f
block|,
literal|0x73746172
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FIPS_ref_point
value|FIPS_text_end
end_define

begin_decl_stmt
specifier|const
name|unsigned
name|int
name|FIPS_rodata_end
index|[]
init|=
block|{
literal|0x46495053
block|,
literal|0x5f726f64
block|,
literal|0x6174615f
block|,
literal|0x656e645b
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * I declare reference function as static in order to avoid certain  * pitfalls in -dynamic linker behaviour...  */
end_comment

begin_function
specifier|static
name|void
modifier|*
name|instruction_pointer
parameter_list|(
name|void
parameter_list|)
block|{
name|void
modifier|*
name|ret
init|=
name|NULL
decl_stmt|;
comment|/* These are ABI-neutral CPU-specific snippets. ABI-neutrality means  * that they are designed to work under any OS running on particular  * CPU, which is why you don't find any #ifdef THIS_OR_THAT_OS in  * this function. */
if|#
directive|if
name|defined
argument_list|(
name|INSTRUCTION_POINTER_IMPLEMENTED
argument_list|)
name|INSTRUCTION_POINTER_IMPLEMENTED
argument_list|(
name|ret
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|__GNUC__
operator|>=
literal|2
if|#
directive|if
name|defined
argument_list|(
name|__alpha
argument_list|)
operator|||
name|defined
argument_list|(
name|__alpha__
argument_list|)
define|#
directive|define
name|INSTRUCTION_POINTER_IMPLEMENTED
asm|__asm __volatile (	"br	%0,1f\n1:" : "=r"(ret) );
elif|#
directive|elif
name|defined
argument_list|(
name|__i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
define|#
directive|define
name|INSTRUCTION_POINTER_IMPLEMENTED
asm|__asm __volatile (	"call 1f\n1:	popl %0" : "=r"(ret) );
name|ret
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
operator|(
name|size_t
operator|)
name|ret
operator|&
operator|~
literal|3UL
operator|)
expr_stmt|;
comment|/* align for better performance */
elif|#
directive|elif
name|defined
argument_list|(
name|__ia64
argument_list|)
operator|||
name|defined
argument_list|(
name|__ia64__
argument_list|)
define|#
directive|define
name|INSTRUCTION_POINTER_IMPLEMENTED
asm|__asm __volatile (	"mov	%0=ip" : "=r"(ret) );
elif|#
directive|elif
name|defined
argument_list|(
name|__hppa
argument_list|)
operator|||
name|defined
argument_list|(
name|__hppa__
argument_list|)
operator|||
name|defined
argument_list|(
name|__pa_risc
argument_list|)
define|#
directive|define
name|INSTRUCTION_POINTER_IMPLEMENTED
asm|__asm __volatile (	"blr	%%r0,%0\n\tnop" : "=r"(ret) );
name|ret
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
operator|(
name|size_t
operator|)
name|ret
operator|&
operator|~
literal|3UL
operator|)
expr_stmt|;
comment|/* mask privilege level */
elif|#
directive|elif
name|defined
argument_list|(
name|__mips
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips__
argument_list|)
define|#
directive|define
name|INSTRUCTION_POINTER_IMPLEMENTED
name|void
modifier|*
name|scratch
decl_stmt|;
asm|__asm __volatile (	"move	%1,$31\n\t"
comment|/* save ra */
literal|"bal	.+8; nop\n\t"
literal|"move	%0,$31\n\t"
literal|"move	$31,%1"
comment|/* restore ra */
operator|:
literal|"=r"
operator|(
name|ret
operator|)
operator|,
literal|"=r"
operator|(
name|scratch
operator|)
block|)
function|;
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ppc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__POWERPC__
argument_list|)
operator|||
name|defined
argument_list|(
name|_POWER
argument_list|)
operator|||
name|defined
argument_list|(
name|__PPC__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__PPC64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|INSTRUCTION_POINTER_IMPLEMENTED
end_define

begin_decl_stmt
name|void
modifier|*
name|scratch
decl_stmt|;
end_decl_stmt

begin_asm
asm|__asm __volatile (	"mfspr	%1,8\n\t"
end_asm

begin_comment
comment|/* save lr */
end_comment

begin_expr_stmt
literal|"bl	$+4\n\t"
literal|"mfspr	%0,8\n\t"
comment|/* mflr ret */
literal|"mtspr	8,%1"
comment|/* restore lr */
operator|:
literal|"=r"
operator|(
name|ret
operator|)
operator|,
literal|"=r"
operator|(
name|scratch
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__s390__
argument_list|)
operator|||
name|defined
argument_list|(
name|__s390x__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|INSTRUCTION_POINTER_IMPLEMENTED
end_define

begin_asm
asm|__asm __volatile (	"bras	%0,1f\n1:" : "=r"(ret) );
end_asm

begin_expr_stmt
name|ret
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
operator|(
name|size_t
operator|)
name|ret
operator|&
operator|~
literal|3UL
operator|)
expr_stmt|;
end_expr_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sparc
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparcv9
argument_list|)
end_elif

begin_define
define|#
directive|define
name|INSTRUCTION_POINTER_IMPLEMENTED
end_define

begin_decl_stmt
name|void
modifier|*
name|scratch
decl_stmt|;
end_decl_stmt

begin_asm
asm|__asm __volatile (	"mov	%%o7,%1\n\t"
end_asm

begin_expr_stmt
literal|"call	.+8; nop\n\t"
literal|"mov	%%o7,%0\n\t"
literal|"mov	%1,%%o7"
operator|:
literal|"=r"
operator|(
name|ret
operator|)
operator|,
literal|"=r"
operator|(
name|scratch
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__x86_64
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|INSTRUCTION_POINTER_IMPLEMENTED
end_define

begin_asm
asm|__asm __volatile (	"leaq	0(%%rip),%0" : "=r"(ret) );
end_asm

begin_expr_stmt
name|ret
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
operator|(
name|size_t
operator|)
name|ret
operator|&
operator|~
literal|3UL
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* align for better performance */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__DECC
argument_list|)
operator|&&
name|defined
argument_list|(
name|__alpha
argument_list|)
end_elif

begin_define
define|#
directive|define
name|INSTRUCTION_POINTER_IMPLEMENTED
end_define

begin_expr_stmt
name|ret
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
name|size_t
operator|)
end_expr_stmt

begin_asm
asm|asm("br %v0,1f\n1:");
end_asm

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|defined
argument_list|(
name|_M_IX86
argument_list|)
end_elif

begin_define
define|#
directive|define
name|INSTRUCTION_POINTER_IMPLEMENTED
end_define

begin_decl_stmt
name|void
modifier|*
name|scratch
decl_stmt|;
end_decl_stmt

begin_macro
name|_asm
end_macro

begin_block
block|{
name|call
name|self
name|self
range|:
name|pop
name|eax
name|mov
name|scratch
decl_stmt|,
name|eax
block|}
end_block

begin_expr_stmt
name|ret
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
operator|(
name|size_t
operator|)
name|scratch
operator|&
operator|~
literal|3UL
operator|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_return
return|return
name|ret
return|;
end_return

begin_comment
unit|}
comment|/*  * This function returns pointer to an instruction in the vicinity of  * its entry point, but not outside this object module. This guarantees  * that sequestered code is covered...  */
end_comment

begin_expr_stmt
unit|void
operator|*
name|FIPS_ref_point
argument_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|INSTRUCTION_POINTER_IMPLEMENTED
argument_list|)
return|return
name|instruction_pointer
argument_list|()
return|;
comment|/* Below we essentially cover vendor compilers which do not support  * inline assembler... */
elif|#
directive|elif
name|defined
argument_list|(
name|_AIX
argument_list|)
block|struct
block|{
name|void
operator|*
name|ip
block|,
operator|*
name|gp
block|,
operator|*
name|env
block|; }
operator|*
name|p
operator|=
operator|(
name|void
operator|*
operator|)
name|instruction_pointer
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|p
operator|->
name|ip
return|;
end_return

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_HPUX_SOURCE
argument_list|)
end_elif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__hppa
argument_list|)
operator|||
name|defined
argument_list|(
name|__hppa__
argument_list|)
end_if

begin_struct
struct|struct
block|{
name|void
modifier|*
name|i
index|[
literal|4
index|]
decl_stmt|;
block|}
modifier|*
name|p
init|=
operator|(
name|void
operator|*
operator|)
name|FIPS_ref_point
struct|;
end_struct

begin_if
if|if
condition|(
sizeof|sizeof
argument_list|(
name|p
argument_list|)
operator|==
literal|8
condition|)
comment|/* 64-bit */
return|return
name|p
operator|->
name|i
index|[
literal|2
index|]
return|;
elseif|else
if|if
condition|(
operator|(
name|size_t
operator|)
name|p
operator|&
literal|2
condition|)
block|{
name|p
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
operator|(
name|size_t
operator|)
name|p
operator|&
operator|~
literal|3UL
operator|)
expr_stmt|;
return|return
name|p
operator|->
name|i
index|[
literal|0
index|]
return|;
block|}
else|else
return|return
operator|(
name|void
operator|*
operator|)
name|p
return|;
end_if

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ia64
argument_list|)
operator|||
name|defined
argument_list|(
name|__ia64__
argument_list|)
end_elif

begin_struct
struct|struct
block|{
name|unsigned
name|long
name|long
name|ip
decl_stmt|,
name|gp
decl_stmt|;
block|}
modifier|*
name|p
init|=
operator|(
name|void
operator|*
operator|)
name|instruction_pointer
struct|;
end_struct

begin_return
return|return
operator|(
name|void
operator|*
operator|)
operator|(
name|size_t
operator|)
name|p
operator|->
name|ip
return|;
end_return

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|__VMS
argument_list|)
operator|||
name|defined
argument_list|(
name|VMS
argument_list|)
operator|)
operator|&&
operator|!
operator|(
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|__vax__
argument_list|)
operator|)
end_elif

begin_comment
comment|/* applies to both alpha and ia64 */
end_comment

begin_struct
struct|struct
block|{
name|unsigned
name|__int64
name|opaque
decl_stmt|,
name|ip
decl_stmt|;
block|}
modifier|*
name|p
init|=
operator|(
name|void
operator|*
operator|)
name|instruction_pointer
struct|;
end_struct

begin_return
return|return
operator|(
name|void
operator|*
operator|)
operator|(
name|size_t
operator|)
name|p
operator|->
name|ip
return|;
end_return

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__VOS__
argument_list|)
end_elif

begin_comment
comment|/* applies to both pa-risc and ia32 */
end_comment

begin_struct
struct|struct
block|{
name|void
modifier|*
name|dp
decl_stmt|,
modifier|*
name|ip
decl_stmt|,
modifier|*
name|gp
decl_stmt|;
block|}
modifier|*
name|p
init|=
operator|(
name|void
operator|*
operator|)
name|instruction_pointer
struct|;
end_struct

begin_return
return|return
name|p
operator|->
name|ip
return|;
end_return

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_elif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN64
argument_list|)
operator|&&
name|defined
argument_list|(
name|_M_IA64
argument_list|)
end_if

begin_struct
struct|struct
block|{
name|void
modifier|*
name|ip
decl_stmt|,
modifier|*
name|gp
decl_stmt|;
block|}
modifier|*
name|p
init|=
operator|(
name|void
operator|*
operator|)
name|FIPS_ref_point
struct|;
end_struct

begin_return
return|return
name|p
operator|->
name|ip
return|;
end_return

begin_else
else|#
directive|else
end_else

begin_return
return|return
operator|(
name|void
operator|*
operator|)
name|FIPS_ref_point
return|;
end_return

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * In case you wonder why there is no #ifdef __linux. All Linux targets  * are GCC-based and therefore are covered by instruction_pointer above  * [well, some are covered by by the one below]...  */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|POINTER_TO_FUNCTION_IS_POINTER_TO_1ST_INSTRUCTION
argument_list|)
end_elif

begin_return
return|return
operator|(
name|void
operator|*
operator|)
name|instruction_pointer
return|;
end_return

begin_else
else|#
directive|else
end_else

begin_return
return|return
name|NULL
return|;
end_return

begin_endif
endif|#
directive|endif
end_endif

unit|}
end_unit

