begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* PowerPC asm definitions for GNU C.  */
end_comment

begin_comment
comment|/* Under winnt, 1) gas supports the following as names and 2) in particular    defining "toc" breaks the FUNC_START macro as ".toc" becomes ".2" */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__WINNT__
argument_list|)
end_if

begin_define
define|#
directive|define
name|r0
value|0
end_define

begin_define
define|#
directive|define
name|sp
value|1
end_define

begin_define
define|#
directive|define
name|toc
value|2
end_define

begin_define
define|#
directive|define
name|r3
value|3
end_define

begin_define
define|#
directive|define
name|r4
value|4
end_define

begin_define
define|#
directive|define
name|r5
value|5
end_define

begin_define
define|#
directive|define
name|r6
value|6
end_define

begin_define
define|#
directive|define
name|r7
value|7
end_define

begin_define
define|#
directive|define
name|r8
value|8
end_define

begin_define
define|#
directive|define
name|r9
value|9
end_define

begin_define
define|#
directive|define
name|r10
value|10
end_define

begin_define
define|#
directive|define
name|r11
value|11
end_define

begin_define
define|#
directive|define
name|r12
value|12
end_define

begin_define
define|#
directive|define
name|r13
value|13
end_define

begin_define
define|#
directive|define
name|r14
value|14
end_define

begin_define
define|#
directive|define
name|r15
value|15
end_define

begin_define
define|#
directive|define
name|r16
value|16
end_define

begin_define
define|#
directive|define
name|r17
value|17
end_define

begin_define
define|#
directive|define
name|r18
value|18
end_define

begin_define
define|#
directive|define
name|r19
value|19
end_define

begin_define
define|#
directive|define
name|r20
value|20
end_define

begin_define
define|#
directive|define
name|r21
value|21
end_define

begin_define
define|#
directive|define
name|r22
value|22
end_define

begin_define
define|#
directive|define
name|r23
value|23
end_define

begin_define
define|#
directive|define
name|r24
value|24
end_define

begin_define
define|#
directive|define
name|r25
value|25
end_define

begin_define
define|#
directive|define
name|r26
value|26
end_define

begin_define
define|#
directive|define
name|r27
value|27
end_define

begin_define
define|#
directive|define
name|r28
value|28
end_define

begin_define
define|#
directive|define
name|r29
value|29
end_define

begin_define
define|#
directive|define
name|r30
value|30
end_define

begin_define
define|#
directive|define
name|r31
value|31
end_define

begin_define
define|#
directive|define
name|cr0
value|0
end_define

begin_define
define|#
directive|define
name|cr1
value|1
end_define

begin_define
define|#
directive|define
name|cr2
value|2
end_define

begin_define
define|#
directive|define
name|cr3
value|3
end_define

begin_define
define|#
directive|define
name|cr4
value|4
end_define

begin_define
define|#
directive|define
name|cr5
value|5
end_define

begin_define
define|#
directive|define
name|cr6
value|6
end_define

begin_define
define|#
directive|define
name|cr7
value|7
end_define

begin_define
define|#
directive|define
name|f0
value|0
end_define

begin_define
define|#
directive|define
name|f1
value|1
end_define

begin_define
define|#
directive|define
name|f2
value|2
end_define

begin_define
define|#
directive|define
name|f3
value|3
end_define

begin_define
define|#
directive|define
name|f4
value|4
end_define

begin_define
define|#
directive|define
name|f5
value|5
end_define

begin_define
define|#
directive|define
name|f6
value|6
end_define

begin_define
define|#
directive|define
name|f7
value|7
end_define

begin_define
define|#
directive|define
name|f8
value|8
end_define

begin_define
define|#
directive|define
name|f9
value|9
end_define

begin_define
define|#
directive|define
name|f10
value|10
end_define

begin_define
define|#
directive|define
name|f11
value|11
end_define

begin_define
define|#
directive|define
name|f12
value|12
end_define

begin_define
define|#
directive|define
name|f13
value|13
end_define

begin_define
define|#
directive|define
name|f14
value|14
end_define

begin_define
define|#
directive|define
name|f15
value|15
end_define

begin_define
define|#
directive|define
name|f16
value|16
end_define

begin_define
define|#
directive|define
name|f17
value|17
end_define

begin_define
define|#
directive|define
name|f18
value|18
end_define

begin_define
define|#
directive|define
name|f19
value|19
end_define

begin_define
define|#
directive|define
name|f20
value|20
end_define

begin_define
define|#
directive|define
name|f21
value|21
end_define

begin_define
define|#
directive|define
name|f22
value|22
end_define

begin_define
define|#
directive|define
name|f23
value|23
end_define

begin_define
define|#
directive|define
name|f24
value|24
end_define

begin_define
define|#
directive|define
name|f25
value|25
end_define

begin_define
define|#
directive|define
name|f26
value|26
end_define

begin_define
define|#
directive|define
name|f27
value|27
end_define

begin_define
define|#
directive|define
name|f28
value|28
end_define

begin_define
define|#
directive|define
name|f29
value|29
end_define

begin_define
define|#
directive|define
name|f30
value|30
end_define

begin_define
define|#
directive|define
name|f31
value|31
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Macros to glue together two tokens.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|XGLUE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a##b
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XGLUE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a
comment|/**/
value|b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GLUE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|XGLUE(a,b)
end_define

begin_comment
comment|/*  * Macros to begin and end a function written in assembler.  If -mcall-aixdesc  * or -mcall-nt, create a function descriptor with the given name, and create  * the real function with one or two leading periods respectively.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_RELOCATABLE
end_ifdef

begin_define
define|#
directive|define
name|DESC_SECTION
value|".got2"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DESC_SECTION
value|".got1"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_CALL_AIXDESC
argument_list|)
end_if

begin_define
define|#
directive|define
name|FUNC_NAME
parameter_list|(
name|name
parameter_list|)
value|GLUE(.,name)
end_define

begin_define
define|#
directive|define
name|FUNC_START
parameter_list|(
name|name
parameter_list|)
define|\
value|.section DESC_SECTION,"aw"; \ name: \ 	.long GLUE(.,name); \ 	.long _GLOBAL_OFFSET_TABLE_; \ 	.long 0; \ 	.previous; \ 	.type GLUE(.,name),@function; \ 	.globl name; \ 	.globl GLUE(.,name); \ GLUE(.,name):
end_define

begin_define
define|#
directive|define
name|FUNC_END
parameter_list|(
name|name
parameter_list|)
define|\
value|GLUE(.L,name): \ 	.size GLUE(.,name),GLUE(.L,name)-GLUE(.,name)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__WINNT__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|FUNC_NAME
parameter_list|(
name|name
parameter_list|)
value|GLUE(..,name)
end_define

begin_define
define|#
directive|define
name|FUNC_START
parameter_list|(
name|name
parameter_list|)
define|\
value|.pdata; \ 	.align 2; \ 	.ualong GLUE(..,name),GLUE(name,.e),0,0,GLUE(..,name); \ 	.reldata; \ name: \ 	.ualong GLUE(..,name),.toc; \ 	.section .text; \ 	.globl name; \ 	.globl GLUE(..,name); \ GLUE(..,name):
end_define

begin_define
define|#
directive|define
name|FUNC_END
parameter_list|(
name|name
parameter_list|)
define|\
value|GLUE(name,.e): ; \ GLUE(FE_MOT_RESVD..,name):
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_CALL_NT
argument_list|)
end_elif

begin_define
define|#
directive|define
name|FUNC_NAME
parameter_list|(
name|name
parameter_list|)
value|GLUE(..,name)
end_define

begin_define
define|#
directive|define
name|FUNC_START
parameter_list|(
name|name
parameter_list|)
define|\
value|.section DESC_SECTION,"aw"; \ name: \ 	.long GLUE(..,name); \ 	.long _GLOBAL_OFFSET_TABLE_; \ 	.previous; \ 	.type GLUE(..,name),@function; \ 	.globl name; \ 	.globl GLUE(..,name); \ GLUE(..,name):
end_define

begin_define
define|#
directive|define
name|FUNC_END
parameter_list|(
name|name
parameter_list|)
define|\
value|GLUE(.L,name): \ 	.size GLUE(..,name),GLUE(.L,name)-GLUE(..,name)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FUNC_NAME
parameter_list|(
name|name
parameter_list|)
value|name
end_define

begin_define
define|#
directive|define
name|FUNC_START
parameter_list|(
name|name
parameter_list|)
define|\
value|.type name,@function; \ 	.globl name; \ name:
end_define

begin_define
define|#
directive|define
name|FUNC_END
parameter_list|(
name|name
parameter_list|)
define|\
value|GLUE(.L,name): \ 	.size name,GLUE(.L,name)-name
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

