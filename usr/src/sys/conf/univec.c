begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	univec.c	4.1	11/9/80	*/
end_comment

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/vm.h"
end_include

begin_comment
comment|/* DEV puts controller no. in bits 27-31 of ISR addr */
end_comment

begin_define
define|#
directive|define
name|DEV
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|(int (*)())((int)(x) + 0x08000000 * n)
end_define

begin_comment
comment|/* DMA sets low bit to activate pseudo-dma code */
end_comment

begin_define
define|#
directive|define
name|DMA
parameter_list|(
name|x
parameter_list|)
value|(int (*)())((int)(x) + 1)
end_define

begin_comment
comment|/* dzxint is, in reality, a pseudo-dma entry */
end_comment

begin_define
define|#
directive|define
name|dzxint
value|DMA(dzdma)
end_define

begin_comment
comment|/*  * Definitions of functions to be placed in UNIvec.  */
end_comment

begin_extern
extern|extern	ubastray(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_include
include|#
directive|include
file|"dz.h"
end_include

begin_if
if|#
directive|if
name|NDZ11
operator|>
literal|0
end_if

begin_extern
extern|extern	dzrint(
end_extern

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|dzdma
argument_list|()
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dzrint
value|ubastray
end_define

begin_define
define|#
directive|define
name|dzxint
value|ubastray
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"dh.h"
end_include

begin_if
if|#
directive|if
name|NDH11
operator|>
literal|0
end_if

begin_extern
extern|extern	dhrint(
end_extern

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|dhxint
argument_list|()
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dhrint
value|ubastray
end_define

begin_define
define|#
directive|define
name|dhxint
value|ubastray
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"up.h"
end_include

begin_if
if|#
directive|if
name|NUP
operator|>
literal|0
end_if

begin_extern
extern|extern	upintr(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|upintr
value|ubastray
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"vp.h"
end_include

begin_if
if|#
directive|if
name|NVP
operator|>
literal|0
end_if

begin_extern
extern|extern	vpintr(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vpintr
value|ubastray
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"va.h"
end_include

begin_if
if|#
directive|if
name|NVA
operator|>
literal|0
end_if

begin_extern
extern|extern	vaintr(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vaintr
value|ubastray
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|___
value|ubastray
end_define

begin_comment
comment|/* fill in the blank! */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|UNIvec
index|[
name|NBPG
operator|/
name|NBPW
index|]
function_decl|)
parameter_list|()
init|=
block|{
comment|/* 0x0 */
name|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
comment|/* 0x10 */
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
comment|/* 0x20 */
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
comment|/* 0x30 */
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
comment|/* 0x40 */
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
comment|/* 0x50 */
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
comment|/* 0x60 */
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
comment|/* 0x70 */
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|vaintr
operator|,
function_decl|vpintr
operator|,
comment|/* 0x80 */
function_decl|vpintr
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
comment|/* 0x90 */
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
comment|/* 0xa0 */
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|upintr
operator|,
comment|/* 0xb0 */
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
function_decl|___
operator|,
if|#
directive|if
name|NDZ11
operator|>
literal|0
comment|/* 0xc0 */
function_decl|DEV
parameter_list|(
name|dzrint
parameter_list|,
function_decl|0
end_function_decl

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|DEV
argument_list|(
name|dzxint
argument_list|,
literal|0
argument_list|)
operator|,
else|#
directive|else
comment|/* 0xc0 */
name|___
operator|,
name|___
operator|,
endif|#
directive|endif
if|#
directive|if
name|NDZ11
operator|>
literal|1
comment|/* 0xc8 */
name|DEV
argument_list|(
name|dzrint
argument_list|,
literal|1
argument_list|)
operator|,
name|DEV
argument_list|(
name|dzxint
argument_list|,
literal|1
argument_list|)
operator|,
else|#
directive|else
comment|/* 0xc8 */
name|___
operator|,
name|___
operator|,
endif|#
directive|endif
if|#
directive|if
name|NDZ11
operator|>
literal|2
comment|/* 0xd0 */
name|DEV
argument_list|(
name|dzrint
argument_list|,
literal|2
argument_list|)
operator|,
name|DEV
argument_list|(
name|dzxint
argument_list|,
literal|2
argument_list|)
operator|,
else|#
directive|else
comment|/* 0xd0 */
name|___
operator|,
name|___
operator|,
endif|#
directive|endif
if|#
directive|if
name|NDZ11
operator|>
literal|3
comment|/* 0xd8 */
name|DEV
argument_list|(
name|dzrint
argument_list|,
literal|3
argument_list|)
operator|,
name|DEV
argument_list|(
name|dzxint
argument_list|,
literal|3
argument_list|)
operator|,
else|#
directive|else
comment|/* 0xd8 */
name|___
operator|,
name|___
operator|,
endif|#
directive|endif
if|#
directive|if
name|NDH11
operator|>
literal|0
comment|/* 0xe0 */
name|DEV
argument_list|(
name|dhrint
argument_list|,
literal|0
argument_list|)
operator|,
name|DEV
argument_list|(
name|dhxint
argument_list|,
literal|0
argument_list|)
operator|,
else|#
directive|else
comment|/* 0xe0 */
name|___
operator|,
name|___
operator|,
endif|#
directive|endif
if|#
directive|if
name|NDH11
operator|>
literal|16
comment|/* 0xe0 */
name|DEV
argument_list|(
name|dhrint
argument_list|,
literal|1
argument_list|)
operator|,
name|DEV
argument_list|(
name|dhxint
argument_list|,
literal|1
argument_list|)
operator|,
else|#
directive|else
comment|/* 0xf0 */
name|___
operator|,
name|___
operator|,
endif|#
directive|endif
comment|/* 0xf0 */
name|___
operator|,
name|___
operator|,
name|___
operator|,
name|___
operator|,
comment|/* 0x100 */
name|___
operator|,
name|___
operator|,
name|___
operator|,
name|___
operator|,
comment|/* 0x110 */
name|___
operator|,
name|___
operator|,
name|___
operator|,
name|___
operator|,
comment|/* 0x120 */
name|___
operator|,
name|___
operator|,
name|___
operator|,
name|___
operator|,
comment|/* 0x130 */
name|___
operator|,
name|___
operator|,
name|___
operator|,
name|___
operator|,
comment|/* 0x140 */
name|___
operator|,
name|___
operator|,
name|___
operator|,
name|___
operator|,
comment|/* 0x150 */
name|___
operator|,
name|___
operator|,
name|___
operator|,
name|___
operator|,
comment|/* 0x160 */
name|___
operator|,
name|___
operator|,
name|___
operator|,
name|___
operator|,
comment|/* 0x170 */
name|___
operator|,
name|___
operator|,
name|___
operator|,
name|___
operator|,
comment|/* 0x180 */
name|___
operator|,
name|___
operator|,
name|___
operator|,
name|___
operator|,
comment|/* 0x190 */
name|___
operator|,
name|___
operator|,
name|___
operator|,
name|___
operator|,
comment|/* 0x1a0 */
name|___
operator|,
name|___
operator|,
name|___
operator|,
name|___
operator|,
comment|/* 0x1b0 */
name|___
operator|,
name|___
operator|,
name|___
operator|,
name|___
operator|,
comment|/* 0x1c0 */
name|___
operator|,
name|___
operator|,
name|___
operator|,
name|___
operator|,
comment|/* 0x1d0 */
name|___
operator|,
name|___
operator|,
name|___
operator|,
name|___
operator|,
comment|/* 0x1e0 */
name|___
operator|,
name|___
operator|,
name|___
operator|,
name|___
operator|,
comment|/* 0x1f0 */
name|___
operator|,
name|___
operator|,
name|___
operator|,
name|___
operator|,
end_expr_stmt

begin_undef
unit|};
undef|#
directive|undef
name|___
end_undef

begin_macro
name|ubastray
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
ifdef|#
directive|ifdef
name|lint
name|i
operator|=
literal|0
expr_stmt|;
else|#
directive|else
asm|asm("movl r3,r11");
comment|/* magic */
endif|#
directive|endif
name|printf
argument_list|(
literal|"stray UBA interrupt: 0x%X\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

