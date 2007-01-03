begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************  The author of this software is David M. Gay.  Copyright (C) 2005 by David M. Gay All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that the copyright notice and this permission notice and warranty disclaimer appear in supporting documentation, and that the name of the author or any of his current or former employers not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL THE AUTHOR OR ANY OF HIS CURRENT OR FORMER EMPLOYERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ****************************************************************/
end_comment

begin_comment
comment|/* Please send bug reports to David M. Gay (dmg at acm dot org,  * with " at " changed at "@" and " dot " changed to ".").	*/
end_comment

begin_comment
comment|/* Program to compute quiet NaNs of various precisions (float,	*/
end_comment

begin_comment
comment|/* double, and perhaps long double) on the current system,	*/
end_comment

begin_comment
comment|/* provided the system uses binary IEEE (P754) arithmetic.	*/
end_comment

begin_comment
comment|/* Note that one system's quiet NaN may be a signaling NaN on	*/
end_comment

begin_comment
comment|/* another system.  The IEEE arithmetic standards (P754, P854)	*/
end_comment

begin_comment
comment|/* do not specify how to distinguish signaling NaNs from quiet	*/
end_comment

begin_comment
comment|/* ones, and this detail varies across systems.	 The computed	*/
end_comment

begin_comment
comment|/* NaN values are encoded in #defines for values for an		*/
end_comment

begin_comment
comment|/* unsigned 32-bit integer type, called Ulong below, and	*/
end_comment

begin_comment
comment|/* (for long double) perhaps as unsigned short values.  Once	*/
end_comment

begin_comment
comment|/* upon a time, there were PC compilers for Intel CPUs that	*/
end_comment

begin_comment
comment|/* had sizeof(long double) = 10.  Are such compilers still	*/
end_comment

begin_comment
comment|/* distributed?							*/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"arith.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|Long
end_ifndef

begin_define
define|#
directive|define
name|Long
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|Long
name|Ulong
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|HAVE_IEEE
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|IEEE_8087
end_ifdef

begin_define
define|#
directive|define
name|_0
value|1
end_define

begin_define
define|#
directive|define
name|_1
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_IEEE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IEEE_MC68k
end_ifdef

begin_define
define|#
directive|define
name|_0
value|0
end_define

begin_define
define|#
directive|define
name|_1
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_IEEE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UL
value|(unsigned long)
end_define

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|HAVE_IEEE
typedef|typedef
union|union
block|{
name|float
name|f
decl_stmt|;
name|double
name|d
decl_stmt|;
name|Ulong
name|L
index|[
literal|4
index|]
decl_stmt|;
ifndef|#
directive|ifndef
name|NO_LONG_LONG
name|unsigned
name|short
name|u
index|[
literal|5
index|]
decl_stmt|;
name|long
name|double
name|D
decl_stmt|;
endif|#
directive|endif
block|}
name|U
typedef|;
name|U
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
name|int
name|i
decl_stmt|;
name|a
operator|.
name|L
index|[
literal|0
index|]
operator|=
name|b
operator|.
name|L
index|[
literal|0
index|]
operator|=
literal|0x7f800000
expr_stmt|;
name|c
operator|.
name|f
operator|=
name|a
operator|.
name|f
operator|-
name|b
operator|.
name|f
expr_stmt|;
name|printf
argument_list|(
literal|"#define f_QNAN 0x%lx\n"
argument_list|,
argument|UL c.L[
literal|0
argument|]
argument_list|)
empty_stmt|;
name|a
operator|.
name|L
index|[
name|_0
index|]
operator|=
name|b
operator|.
name|L
index|[
name|_0
index|]
operator|=
literal|0x7ff00000
expr_stmt|;
name|a
operator|.
name|L
index|[
name|_1
index|]
operator|=
name|b
operator|.
name|L
index|[
name|_1
index|]
operator|=
literal|0
expr_stmt|;
name|c
operator|.
name|d
operator|=
name|a
operator|.
name|d
operator|-
name|b
operator|.
name|d
expr_stmt|;
comment|/* quiet NaN */
name|printf
argument_list|(
literal|"#define d_QNAN0 0x%lx\n"
argument_list|,
argument|UL c.L[
literal|0
argument|]
argument_list|)
empty_stmt|;
name|printf
argument_list|(
literal|"#define d_QNAN1 0x%lx\n"
argument_list|,
argument|UL c.L[
literal|1
argument|]
argument_list|)
empty_stmt|;
ifdef|#
directive|ifdef
name|NO_LONG_LONG
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|4
condition|;
name|i
operator|++
control|)
name|printf
argument_list|(
literal|"#define ld_QNAN%d 0xffffffff\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|5
condition|;
name|i
operator|++
control|)
name|printf
argument_list|(
literal|"#define ldus_QNAN%d 0xffff\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
else|#
directive|else
name|b
operator|.
name|D
operator|=
name|c
operator|.
name|D
operator|=
name|a
operator|.
name|d
expr_stmt|;
if|if
condition|(
name|printf
argument_list|(
literal|""
argument_list|)
operator|<
literal|0
condition|)
name|c
operator|.
name|D
operator|=
literal|37
expr_stmt|;
comment|/* never executed; just defeat optimization */
name|a
operator|.
name|L
index|[
literal|2
index|]
operator|=
name|a
operator|.
name|L
index|[
literal|3
index|]
operator|=
literal|0
expr_stmt|;
name|a
operator|.
name|D
operator|=
name|b
operator|.
name|D
operator|-
name|c
operator|.
name|D
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|4
condition|;
name|i
operator|++
control|)
name|printf
argument_list|(
literal|"#define ld_QNAN%d 0x%lx\n"
argument_list|,
argument|i
argument_list|,
argument|UL a.L[i]
argument_list|)
empty_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|5
condition|;
name|i
operator|++
control|)
name|printf
argument_list|(
literal|"#define ldus_QNAN%d 0x%x\n"
argument_list|,
name|i
argument_list|,
name|a
operator|.
name|u
index|[
name|i
index|]
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* HAVE_IEEE */
return|return
literal|0
return|;
block|}
end_function

end_unit

