begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	align.h	1.1	86/07/20	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Some special registers definitions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SLR
end_ifndef

begin_define
define|#
directive|define
name|SLR
value|1
end_define

begin_define
define|#
directive|define
name|P0LR
value|3
end_define

begin_define
define|#
directive|define
name|P1LR
value|5
end_define

begin_define
define|#
directive|define
name|P2LR
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"../tahoealign/defs.h"
end_include

begin_comment
comment|/*  * Definitions about the stack frame as seen by the routine  * 'alignment' in the kernel. If you ever wondered what's the  * meaning of 'machine dependent code', look here :-)  * This structure is partly set up by locore.s, for 'alignment',  * and partly by the allocation of local variables in 'alignment.c'  * itself.  *    All these things are passed between procedures on the  * (current process' kernel) stack. The alternative (static  * variables) is a little bit more elegant but it works fine  * for one process only. Will not work for multiple processes  * with alignment processing or for MP models of HW.  *  * WARNING : due to the intimate relationships involved, don't  *	change the process_info structure unless you also  *	change the alignment trap code in locore.s AND the  *	allocation of local variables in 'alignment.c' !!  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|Saved_sp
decl_stmt|;
comment|/* For exceptions */
name|long
name|Saved_pc
decl_stmt|;
name|long
name|Last_operand
decl_stmt|;
comment|/* Last operand # processed */
name|long
name|Opcode
decl_stmt|;
comment|/* 'offending' opcode */
name|struct
name|oprnd
name|Decoded
index|[
literal|4
index|]
decl_stmt|;
name|long
name|REG0
decl_stmt|;
name|long
name|REG1
decl_stmt|;
name|long
name|REG2
decl_stmt|;
name|long
name|REG3
decl_stmt|;
name|long
name|REG4
decl_stmt|;
name|long
name|REG5
decl_stmt|;
name|long
name|REG6
decl_stmt|;
name|long
name|REG7
decl_stmt|;
name|long
name|REG8
decl_stmt|;
name|long
name|REG9
decl_stmt|;
name|long
name|REG10
decl_stmt|;
name|long
name|REG11
decl_stmt|;
name|long
name|REG12
decl_stmt|;
name|long
name|return_pc
decl_stmt|;
comment|/* Points into locore.s */
name|long
name|mask_restored
decl_stmt|;
name|long
name|REG13
decl_stmt|;
comment|/* Original, from the process */
name|long
name|Sp
decl_stmt|;
comment|/* Alias R14 */
name|long
name|ret_code
decl_stmt|;
name|long
name|ret_addr
decl_stmt|;
name|long
name|ret_exception
decl_stmt|;
comment|/* To tell locore.s about problems */
name|long
name|Ach
decl_stmt|;
name|long
name|Acl
decl_stmt|;
name|unsigned
name|unused
range|:
literal|30
decl_stmt|;
name|unsigned
name|pcb_acc_pnt
range|:
literal|1
decl_stmt|;
name|unsigned
name|acc_dbl
range|:
literal|1
decl_stmt|;
name|long
name|Pc
decl_stmt|;
comment|/* Alias R15 */
name|long
name|Psl
decl_stmt|;
block|}
name|process_info
typedef|;
end_typedef

begin_define
define|#
directive|define
name|saved_pc
value|(infop->Saved_pc)
end_define

begin_define
define|#
directive|define
name|saved_sp
value|(infop->Saved_sp)
end_define

begin_define
define|#
directive|define
name|last_operand
value|(infop->Last_operand)
end_define

begin_define
define|#
directive|define
name|opCODE
value|(infop->Opcode)
end_define

begin_define
define|#
directive|define
name|decoded
value|(infop->Decoded)
end_define

begin_define
define|#
directive|define
name|r0
value|(infop->REG0)
end_define

begin_define
define|#
directive|define
name|r1
value|(infop->REG1)
end_define

begin_define
define|#
directive|define
name|r2
value|(infop->REG2)
end_define

begin_define
define|#
directive|define
name|r3
value|(infop->REG3)
end_define

begin_define
define|#
directive|define
name|r4
value|(infop->REG4)
end_define

begin_define
define|#
directive|define
name|r5
value|(infop->REG5)
end_define

begin_define
define|#
directive|define
name|r6
value|(infop->REG6)
end_define

begin_define
define|#
directive|define
name|r7
value|(infop->REG7)
end_define

begin_define
define|#
directive|define
name|r8
value|(infop->REG8)
end_define

begin_define
define|#
directive|define
name|r9
value|(infop->REG9)
end_define

begin_define
define|#
directive|define
name|r10
value|(infop->REG10)
end_define

begin_define
define|#
directive|define
name|r11
value|(infop->REG11)
end_define

begin_define
define|#
directive|define
name|r12
value|(infop->REG12)
end_define

begin_define
define|#
directive|define
name|r13
value|(infop->REG13)
end_define

begin_define
define|#
directive|define
name|fp
value|(infop->REG13)
end_define

begin_define
define|#
directive|define
name|sp
value|(infop->Sp)
end_define

begin_define
define|#
directive|define
name|acc_high
value|(infop->Ach)
end_define

begin_define
define|#
directive|define
name|acc_low
value|(infop->Acl)
end_define

begin_define
define|#
directive|define
name|pc
value|(infop->Pc)
end_define

begin_define
define|#
directive|define
name|psl
value|(infop->Psl)
end_define

begin_define
define|#
directive|define
name|PCOUNTER
value|15
end_define

begin_define
define|#
directive|define
name|SPOINTER
value|14
end_define

begin_comment
comment|/*  * Setting new condition codes for the process. #define Set_psl(z)	asm("	movl	z,r6"); \ 			asm("	andl2	$15,r6"); \ 			asm("	mnegl	$1,r7"); \ 			asm("	xorl2	r6,r7"); \ 			asm("	andl2	$15,r7"); \ 			asm("	bicpsw	r7"); \ 			asm("	bispsw	r6")  */
end_comment

begin_define
define|#
directive|define
name|Set_psl
parameter_list|(
name|z
parameter_list|)
value|asm("	andl2	$15,z"); \ 			asm("	mnegl	$1,r6"); \ 			asm("	xorl2	z,r6"); \ 			asm("	andl2	$15,r6"); \ 			asm("	bicpsw	r6"); \ 			asm("	bispsw	z")
end_define

begin_define
define|#
directive|define
name|New_cc
parameter_list|(
name|x
parameter_list|)
value|(x)&= PSL_ALLCC; psl = psl& ~PSL_ALLCC | (x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Definitions for ret_code. NOTE : DON"T USE 0 !! locore.s knows that  *	0 means OK, no problems !  */
end_comment

begin_define
define|#
directive|define
name|ILL_ADDRMOD
value|1
end_define

begin_define
define|#
directive|define
name|ILL_ACCESS
value|2
end_define

begin_define
define|#
directive|define
name|ILL_OPRND
value|3
end_define

begin_define
define|#
directive|define
name|ARITHMETIC
value|4
end_define

begin_define
define|#
directive|define
name|ALIGNMENT
value|5
end_define

begin_comment
comment|/*  * For use in u.u_eosys as a flag.  */
end_comment

begin_define
define|#
directive|define
name|EMULATEALIGN
value|0x80
end_define

end_unit

