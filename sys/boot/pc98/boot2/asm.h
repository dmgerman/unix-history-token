begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Mach Operating System  * Copyright (c) 1991,1990,1989 Carnegie Mellon University  * All Rights Reserved.  *  * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  *  *	from: Mach, Revision 2.7  92/02/29  15:33:41  rpd  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|S_ARG0
value|4(%esp)
end_define

begin_define
define|#
directive|define
name|S_ARG1
value|8(%esp)
end_define

begin_define
define|#
directive|define
name|S_ARG2
value|12(%esp)
end_define

begin_define
define|#
directive|define
name|S_ARG3
value|16(%esp)
end_define

begin_define
define|#
directive|define
name|FRAME
value|pushl %ebp; movl %esp, %ebp
end_define

begin_define
define|#
directive|define
name|EMARF
value|leave
end_define

begin_define
define|#
directive|define
name|B_ARG0
value|8(%ebp)
end_define

begin_define
define|#
directive|define
name|B_ARG1
value|12(%ebp)
end_define

begin_define
define|#
directive|define
name|B_ARG2
value|16(%ebp)
end_define

begin_define
define|#
directive|define
name|B_ARG3
value|20(%ebp)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|wheeze
end_ifdef

begin_define
define|#
directive|define
name|ALIGN
value|4
end_define

begin_define
define|#
directive|define
name|EXT
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|LEXT
parameter_list|(
name|x
parameter_list|)
value|x:
end_define

begin_define
define|#
directive|define
name|LCL
parameter_list|(
name|x
parameter_list|)
value|.
comment|/**/
value|x
end_define

begin_define
define|#
directive|define
name|LB
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|.
comment|/**/
value|x
end_define

begin_define
define|#
directive|define
name|LBb
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|.
comment|/**/
value|x
end_define

begin_define
define|#
directive|define
name|LBf
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|.
comment|/**/
value|x
end_define

begin_define
define|#
directive|define
name|SVC
value|lcall $7,$0
end_define

begin_define
define|#
directive|define
name|String
value|.string
end_define

begin_define
define|#
directive|define
name|Value
value|.value
end_define

begin_define
define|#
directive|define
name|Times
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|[a\*b]
end_define

begin_define
define|#
directive|define
name|Divide
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|[a\\b]
end_define

begin_define
define|#
directive|define
name|INB
value|inb	(%dx)
end_define

begin_define
define|#
directive|define
name|OUTB
value|outb	(%dx)
end_define

begin_define
define|#
directive|define
name|INL
value|inl	(%dx)
end_define

begin_define
define|#
directive|define
name|OUTL
value|outl	(%dx)
end_define

begin_else
else|#
directive|else
else|wheeze
end_else

begin_define
define|#
directive|define
name|ALIGN
end_define

begin_define
define|#
directive|define
name|LCL
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|LB
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|n
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|EXT
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|LEXT
parameter_list|(
name|x
parameter_list|)
value|x ## :
end_define

begin_define
define|#
directive|define
name|LBb
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|n ## b
end_define

begin_define
define|#
directive|define
name|LBf
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|n ## f
end_define

begin_else
else|#
directive|else
else|__STDC__
end_else

begin_define
define|#
directive|define
name|EXT
parameter_list|(
name|x
parameter_list|)
value|_
comment|/**/
value|x
end_define

begin_define
define|#
directive|define
name|LEXT
parameter_list|(
name|x
parameter_list|)
value|_
comment|/**/
value|x
comment|/**/
value|:
end_define

begin_define
define|#
directive|define
name|LBb
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|n
comment|/**/
value|b
end_define

begin_define
define|#
directive|define
name|LBf
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|n
comment|/**/
value|f
end_define

begin_endif
endif|#
directive|endif
endif|__STDC__
end_endif

begin_define
define|#
directive|define
name|SVC
value|.byte 0x9a; .long 0; .word 0x7
end_define

begin_define
define|#
directive|define
name|String
value|.ascii
end_define

begin_define
define|#
directive|define
name|Value
value|.word
end_define

begin_define
define|#
directive|define
name|Times
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a*b)
end_define

begin_define
define|#
directive|define
name|Divide
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a/b)
end_define

begin_define
define|#
directive|define
name|INB
value|inb	%dx, %al
end_define

begin_define
define|#
directive|define
name|OUTB
value|outb	%al, %dx
end_define

begin_define
define|#
directive|define
name|INL
value|inl	%dx, %eax
end_define

begin_define
define|#
directive|define
name|OUTL
value|outl	%eax, %dx
end_define

begin_endif
endif|#
directive|endif
endif|wheeze
end_endif

begin_define
define|#
directive|define
name|addr32
value|.byte 0x67
end_define

begin_define
define|#
directive|define
name|data32
value|.byte 0x66
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GPROF
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|MCOUNT
value|.data; LB(x, 9); .long 0; .text; lea LBb(x, 9),%edx; call mcount
end_define

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|.globl EXT(x); .align ALIGN; LEXT(x) ; \ 			pushl %ebp; movl %esp, %ebp; MCOUNT; popl %ebp;
end_define

begin_define
define|#
directive|define
name|ENTRY2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|.globl EXT(x); .globl EXT(y); \ 			.align ALIGN; LEXT(x) LEXT(y) ; \ 			pushl %ebp; movl %esp, %ebp; MCOUNT; popl %ebp;
end_define

begin_define
define|#
directive|define
name|ASENTRY
parameter_list|(
name|x
parameter_list|)
value|.globl x; .align ALIGN; x ## : ; \   			pushl %ebp; movl %esp, %ebp; MCOUNT; popl %ebp;
end_define

begin_else
else|#
directive|else
else|__STDC__
end_else

begin_define
define|#
directive|define
name|MCOUNT
value|.data; LB(x, 9): .long 0; .text; lea LBb(x, 9),%edx; call mcount
end_define

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|.globl EXT(x); .align ALIGN; LEXT(x) ; \ 			pushl %ebp; movl %esp, %ebp; MCOUNT; popl %ebp;
end_define

begin_define
define|#
directive|define
name|ENTRY2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|.globl EXT(x); .globl EXT(y); \ 			.align ALIGN; LEXT(x) LEXT(y)
end_define

begin_define
define|#
directive|define
name|ASENTRY
parameter_list|(
name|x
parameter_list|)
value|.globl x; .align ALIGN; x: ; \   			pushl %ebp; movl %esp, %ebp; MCOUNT; popl %ebp;
end_define

begin_endif
endif|#
directive|endif
endif|__STDC__
end_endif

begin_else
else|#
directive|else
else|GPROF
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|MCOUNT
end_define

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|.globl EXT(x); .align ALIGN; LEXT(x)
end_define

begin_define
define|#
directive|define
name|ENTRY2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|.globl EXT(x); .globl EXT(y); \ 			.align ALIGN; LEXT(x) LEXT(y)
end_define

begin_define
define|#
directive|define
name|ASENTRY
parameter_list|(
name|x
parameter_list|)
value|.globl x; .align ALIGN; x ## :
end_define

begin_else
else|#
directive|else
else|__STDC__
end_else

begin_define
define|#
directive|define
name|MCOUNT
end_define

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|.globl EXT(x); .align ALIGN; LEXT(x)
end_define

begin_define
define|#
directive|define
name|ENTRY2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|.globl EXT(x); .globl EXT(y); \ 			.align ALIGN; LEXT(x) LEXT(y)
end_define

begin_define
define|#
directive|define
name|ASENTRY
parameter_list|(
name|x
parameter_list|)
value|.globl x; .align ALIGN; x:
end_define

begin_endif
endif|#
directive|endif
endif|__STDC__
end_endif

begin_endif
endif|#
directive|endif
endif|GPROF
end_endif

begin_define
define|#
directive|define
name|Entry
parameter_list|(
name|x
parameter_list|)
value|.globl EXT(x); .align ALIGN; LEXT(x)
end_define

begin_define
define|#
directive|define
name|DATA
parameter_list|(
name|x
parameter_list|)
value|.globl EXT(x); .align ALIGN; LEXT(x)
end_define

end_unit

