begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XFree86: mit/server/ddx/x386/common/compiler.h,v 2.3 1993/10/03 14:55:28 dawes Exp $ */
end_comment

begin_comment
comment|/*  * Copyright 1990,91 by Thomas Roell, Dinkelscherben, Germany.  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of Thomas Roell not be used in  * advertising or publicity pertaining to distribution of the software without  * specific, written prior permission.  Thomas Roell makes no representations  * about the suitability of this software for any purpose.  It is provided  * "as is" without express or implied warranty.  *  * THOMAS ROELL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO  * EVENT SHALL THOMAS ROELL BE LIABLE FOR ANY SPECIAL, INDIRECT OR  * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,  * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER  * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMPILER_H
end_ifndef

begin_define
define|#
directive|define
name|_COMPILER_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|signed
end_ifdef

begin_undef
undef|#
directive|undef
name|signed
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|volatile
end_ifdef

begin_undef
undef|#
directive|undef
name|volatile
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|const
end_ifdef

begin_undef
undef|#
directive|undef
name|const
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|signed
end_define

begin_comment
comment|/**/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|volatile
value|__volatile__
end_define

begin_define
define|#
directive|define
name|const
value|__const__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__STDC__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_INLINE
end_ifdef

begin_function_decl
specifier|extern
name|void
name|outb
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|outw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|inb
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|inw
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_function_decl
specifier|extern
name|unsigned
name|char
name|rdinx
parameter_list|(
name|unsigned
name|short
parameter_list|,
name|unsigned
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|wrinx
parameter_list|(
name|unsigned
name|short
parameter_list|,
name|unsigned
name|char
parameter_list|,
name|unsigned
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|modinx
parameter_list|(
name|unsigned
name|short
parameter_list|,
name|unsigned
name|char
parameter_list|,
name|unsigned
name|char
parameter_list|,
name|unsigned
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|testrg
parameter_list|(
name|unsigned
name|short
parameter_list|,
name|unsigned
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|textinx2
parameter_list|(
name|unsigned
name|short
parameter_list|,
name|unsigned
name|char
parameter_list|,
name|unsigned
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|textinx
parameter_list|(
name|unsigned
name|short
parameter_list|,
name|unsigned
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NeedFunctionProtoypes */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|char
name|rdinx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|wrinx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|modinx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|testrg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|textinx2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|textinx
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NeedFunctionProtoypes */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NO_INLINE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|FAKEIT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|GCCUSESGAS
end_ifdef

begin_comment
comment|/*  * If gcc uses gas rather than the native assembler, the syntax of these  * inlines has to be different.		DHD  */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|outb
parameter_list|(
name|port
parameter_list|,
name|val
parameter_list|)
name|short
name|port
decl_stmt|;
name|char
name|val
decl_stmt|;
block|{
asm|__asm__
specifier|__volatile__
asm|("outb %0,%1" : :"a" (val), "d" (port));
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|outw
parameter_list|(
name|port
parameter_list|,
name|val
parameter_list|)
name|short
name|port
decl_stmt|;
name|short
name|val
decl_stmt|;
block|{
asm|__asm__
specifier|__volatile__
asm|("outw %0,%1" : :"a" (val), "d" (port));
block|}
end_function

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|inb
parameter_list|(
name|port
parameter_list|)
name|short
name|port
decl_stmt|;
block|{
name|unsigned
name|char
name|ret
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("inb %1,%0" :        "=a" (ret) :        "d" (port));
return|return
name|ret
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|inw
parameter_list|(
name|port
parameter_list|)
name|short
name|port
decl_stmt|;
block|{
name|unsigned
name|short
name|ret
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("inw %1,%0" :        "=a" (ret) :        "d" (port));
return|return
name|ret
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* GCCUSESGAS */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|outb
parameter_list|(
name|port
parameter_list|,
name|val
parameter_list|)
name|short
name|port
decl_stmt|;
name|char
name|val
decl_stmt|;
block|{
asm|__asm__
specifier|__volatile__
asm|("out%B0 (%1)" : :"a" (val), "d" (port));
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|outw
parameter_list|(
name|port
parameter_list|,
name|val
parameter_list|)
name|short
name|port
decl_stmt|;
name|short
name|val
decl_stmt|;
block|{
asm|__asm__
specifier|__volatile__
asm|("out%W0 (%1)" : :"a" (val), "d" (port));
block|}
end_function

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|inb
parameter_list|(
name|port
parameter_list|)
name|short
name|port
decl_stmt|;
block|{
name|unsigned
name|char
name|ret
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("in%B0 (%1)" : 		   "=a" (ret) : 		   "d" (port));
return|return
name|ret
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|inw
parameter_list|(
name|port
parameter_list|)
name|short
name|port
decl_stmt|;
block|{
name|unsigned
name|short
name|ret
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("in%W0 (%1)" : 		   "=a" (ret) : 		   "d" (port));
return|return
name|ret
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCCUSESGAS */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* FAKEIT */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|outb
parameter_list|(
name|port
parameter_list|,
name|val
parameter_list|)
name|short
name|port
decl_stmt|;
name|char
name|val
decl_stmt|;
block|{ }
end_function

begin_function
specifier|static
name|__inline__
name|void
name|outw
parameter_list|(
name|port
parameter_list|,
name|val
parameter_list|)
name|short
name|port
decl_stmt|;
name|short
name|val
decl_stmt|;
block|{ }
end_function

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|inb
parameter_list|(
name|port
parameter_list|)
name|short
name|port
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|unsigned
name|int
name|inw
parameter_list|(
name|port
parameter_list|)
name|short
name|port
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FAKEIT */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|AMOEBA
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_MINIX
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
operator|(
name|__STDC__
operator|==
literal|1
operator|)
end_if

begin_define
define|#
directive|define
name|asm
value|__asm
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__USLC__
end_ifndef

begin_define
define|#
directive|define
name|__USLC__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/inline.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *-----------------------------------------------------------------------  * Port manipulation convenience functions  *-----------------------------------------------------------------------  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|__inline__
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * rdinx - read the indexed byte port 'port', index 'ind', and return its value  */
end_comment

begin_function
specifier|static
name|__inline__
name|unsigned
name|char
ifdef|#
directive|ifdef
name|__STDC__
name|rdinx
parameter_list|(
name|unsigned
name|short
name|port
parameter_list|,
name|unsigned
name|char
name|ind
parameter_list|)
else|#
directive|else
function|rdinx
parameter_list|(
name|port
parameter_list|,
name|ind
parameter_list|)
name|unsigned
name|short
name|port
decl_stmt|;
name|unsigned
name|char
name|ind
decl_stmt|;
endif|#
directive|endif
block|{
if|if
condition|(
name|port
operator|==
literal|0x3C0
condition|)
comment|/* reset attribute flip-flop */
operator|(
name|void
operator|)
name|inb
argument_list|(
literal|0x3DA
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|port
argument_list|,
name|ind
argument_list|)
expr_stmt|;
return|return
operator|(
name|inb
argument_list|(
name|port
operator|+
literal|1
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * wrinx - write 'val' to port 'port', index 'ind'  */
end_comment

begin_function
specifier|static
name|__inline__
name|void
ifdef|#
directive|ifdef
name|__STDC__
name|wrinx
parameter_list|(
name|unsigned
name|short
name|port
parameter_list|,
name|unsigned
name|char
name|ind
parameter_list|,
name|unsigned
name|char
name|val
parameter_list|)
else|#
directive|else
function|wrinx
parameter_list|(
name|port
parameter_list|,
name|ind
parameter_list|,
name|val
parameter_list|)
name|unsigned
name|short
name|port
decl_stmt|;
name|unsigned
name|char
name|ind
decl_stmt|,
name|val
decl_stmt|;
endif|#
directive|endif
block|{
name|outb
argument_list|(
name|port
argument_list|,
name|ind
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|port
operator|+
literal|1
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * modinx - in register 'port', index 'ind', set the bits in 'mask' as in 'new';  *	    the other bits are unchanged.  */
end_comment

begin_function
specifier|static
name|__inline__
name|void
ifdef|#
directive|ifdef
name|__STDC__
name|modinx
parameter_list|(
name|unsigned
name|short
name|port
parameter_list|,
name|unsigned
name|char
name|ind
parameter_list|,
name|unsigned
name|char
name|mask
parameter_list|,
name|unsigned
name|char
name|new
parameter_list|)
else|#
directive|else
function|modinx
parameter_list|(
name|port
parameter_list|,
name|ind
parameter_list|,
name|mask
parameter_list|,
name|new
parameter_list|)
name|unsigned
name|short
name|port
decl_stmt|;
name|unsigned
name|char
name|ind
decl_stmt|,
name|mask
decl_stmt|,
name|new
decl_stmt|;
endif|#
directive|endif
block|{
name|unsigned
name|char
name|tmp
decl_stmt|;
name|tmp
operator|=
operator|(
name|rdinx
argument_list|(
name|port
argument_list|,
name|ind
argument_list|)
operator|&
operator|~
name|mask
operator|)
operator||
operator|(
name|new
operator|&
name|mask
operator|)
expr_stmt|;
name|wrinx
argument_list|(
name|port
argument_list|,
name|ind
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * tstrg - returns true iff the bits in 'mask' of register 'port' are  *	   readable& writable.  */
end_comment

begin_function
specifier|static
name|__inline__
name|int
ifdef|#
directive|ifdef
name|__STDC__
name|testrg
parameter_list|(
name|unsigned
name|short
name|port
parameter_list|,
name|unsigned
name|char
name|mask
parameter_list|)
else|#
directive|else
function|tstrg
parameter_list|(
name|port
parameter_list|,
name|mask
parameter_list|)
name|unsigned
name|short
name|port
decl_stmt|;
name|unsigned
name|char
name|mask
decl_stmt|;
endif|#
directive|endif
block|{
name|unsigned
name|char
name|old
decl_stmt|,
name|new1
decl_stmt|,
name|new2
decl_stmt|;
name|old
operator|=
name|inb
argument_list|(
name|port
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|port
argument_list|,
name|old
operator|&
operator|~
name|mask
argument_list|)
expr_stmt|;
name|new1
operator|=
name|inb
argument_list|(
name|port
argument_list|)
operator|&
name|mask
expr_stmt|;
name|outb
argument_list|(
name|port
argument_list|,
name|old
operator||
name|mask
argument_list|)
expr_stmt|;
name|new2
operator|=
name|inb
argument_list|(
name|port
argument_list|)
operator|&
name|mask
expr_stmt|;
name|outb
argument_list|(
name|port
argument_list|,
name|old
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|new1
operator|==
literal|0
operator|)
operator|&&
operator|(
name|new2
operator|==
name|mask
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * testinx2 - returns true iff the bits in 'mask' of register 'port', index  *	      'ind' are readable& writable.  */
end_comment

begin_function
specifier|static
name|__inline__
name|int
ifdef|#
directive|ifdef
name|__STDC__
name|testinx2
parameter_list|(
name|unsigned
name|short
name|port
parameter_list|,
name|unsigned
name|char
name|ind
parameter_list|,
name|unsigned
name|char
name|mask
parameter_list|)
else|#
directive|else
function|testinx2
parameter_list|(
name|port
parameter_list|,
name|ind
parameter_list|,
name|mask
parameter_list|)
name|unsigned
name|short
name|port
decl_stmt|;
name|unsigned
name|char
name|ind
decl_stmt|,
name|mask
decl_stmt|;
endif|#
directive|endif
block|{
name|unsigned
name|char
name|old
decl_stmt|,
name|new1
decl_stmt|,
name|new2
decl_stmt|;
name|old
operator|=
name|rdinx
argument_list|(
name|port
argument_list|,
name|ind
argument_list|)
expr_stmt|;
name|wrinx
argument_list|(
name|port
argument_list|,
name|ind
argument_list|,
name|old
operator|&
operator|~
name|mask
argument_list|)
expr_stmt|;
name|new1
operator|=
name|rdinx
argument_list|(
name|port
argument_list|,
name|ind
argument_list|)
operator|&
name|mask
expr_stmt|;
name|wrinx
argument_list|(
name|port
argument_list|,
name|ind
argument_list|,
name|old
operator||
name|mask
argument_list|)
expr_stmt|;
name|new2
operator|=
name|rdinx
argument_list|(
name|port
argument_list|,
name|ind
argument_list|)
operator|&
name|mask
expr_stmt|;
name|wrinx
argument_list|(
name|port
argument_list|,
name|ind
argument_list|,
name|old
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|new1
operator|==
literal|0
operator|)
operator|&&
operator|(
name|new2
operator|==
name|mask
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * testinx - returns true iff all bits of register 'port', index 'ind' are  *     	     readable& writable.  */
end_comment

begin_function
specifier|static
name|__inline__
name|int
ifdef|#
directive|ifdef
name|__STDC__
name|testinx
parameter_list|(
name|unsigned
name|short
name|port
parameter_list|,
name|unsigned
name|char
name|ind
parameter_list|)
else|#
directive|else
function|testinx
parameter_list|(
name|port
parameter_list|,
name|ind
parameter_list|,
name|mask
parameter_list|)
name|unsigned
name|short
name|port
decl_stmt|;
name|unsigned
name|char
name|ind
decl_stmt|;
endif|#
directive|endif
block|{
return|return
operator|(
name|testinx2
argument_list|(
name|port
argument_list|,
name|ind
argument_list|,
literal|0xFF
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_INLINE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _COMPILER_H */
end_comment

end_unit

