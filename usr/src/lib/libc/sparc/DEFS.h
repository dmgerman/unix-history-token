begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * %sccs.include.redist.c%  *  *	@(#)DEFS.h	5.1 (Berkeley) %G%  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PROF
end_ifdef

begin_define
define|#
directive|define
name|FUNC
parameter_list|(
name|x
parameter_list|)
define|\
value|.align 4; .globl x; .proc 1; x:; .data; .align 4; 1: .long 0; \ 	.text; save %sp,-96,%sp; sethi %hi(1b),%o0; call mcount; \ 	or %lo(1b),%o0,%o0; restore
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FUNC
parameter_list|(
name|x
parameter_list|)
define|\
value|.align 4; .globl x; .proc 1; x:
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|FUNC(_##x)
end_define

end_unit

