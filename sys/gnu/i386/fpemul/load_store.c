begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  load_store.c  *  * This file contains most of the code to interpret the FPU instructions  * which load and store from user memory.  *  *  * Copyright (C) 1992,1993,1994  *                       W. Metzenthen, 22 Parker St, Ormond, Vic 3163,  *                       Australia.  E-mail   billm@vaxc.cc.monash.edu.au  * All rights reserved.  *  * This copyright notice covers the redistribution and use of the  * FPU emulator developed by W. Metzenthen. It covers only its use  * in the 386BSD, FreeBSD and NetBSD operating systems. Any other  * use is not permitted under this copyright.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must include information specifying  *    that source code for the emulator is freely available and include  *    either:  *      a) an offer to provide the source code for a nominal distribution  *         fee, or  *      b) list at least two alternative methods whereby the source  *         can be obtained, e.g. a publically accessible bulletin board  *         and an anonymous ftp site from which the software can be  *         downloaded.  * 3. All advertising materials specifically mentioning features or use of  *    this emulator must acknowledge that it was developed by W. Metzenthen.  * 4. The name of W. Metzenthen may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * W. METZENTHEN BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *  * The purpose of this copyright, based upon the Berkeley copyright, is to  * ensure that the covered software remains freely available to everyone.  *  * The software (with necessary differences) is also available, but under  * the terms of the GNU copyleft, for the Linux operating system and for  * the djgpp ms-dos extender.  *  * W. Metzenthen   June 1994.  *  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------+  | Note:                                                                     |  |    The file contains code which accesses user memory.                     |  |    Emulator static data may change when user memory is accessed, due to   |  |    other processes using the emulator while swapping is in progress.      |  +---------------------------------------------------------------------------*/
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_include
include|#
directive|include
file|<gnu/i386/fpemul/fpu_emu.h>
end_include

begin_include
include|#
directive|include
file|<gnu/i386/fpemul/fpu_system.h>
end_include

begin_include
include|#
directive|include
file|<gnu/i386/fpemul/status_w.h>
end_include

begin_define
define|#
directive|define
name|_NONE_
value|0
end_define

begin_comment
comment|/* FPU_st0_ptr etc not needed */
end_comment

begin_define
define|#
directive|define
name|_REG0_
value|1
end_define

begin_comment
comment|/* Will be storing st(0) */
end_comment

begin_define
define|#
directive|define
name|_PUSH_
value|3
end_define

begin_comment
comment|/* Need to check for space to push onto stack */
end_comment

begin_define
define|#
directive|define
name|_null_
value|4
end_define

begin_comment
comment|/* Function illegal or not implemented */
end_comment

begin_define
define|#
directive|define
name|pop_0
parameter_list|()
value|{ pop_ptr->tag = TW_Empty; top++; }
end_define

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|type_table
index|[
literal|32
index|]
init|=
block|{
name|_PUSH_
block|,
name|_PUSH_
block|,
name|_PUSH_
block|,
name|_PUSH_
block|,
name|_null_
block|,
name|_null_
block|,
name|_null_
block|,
name|_null_
block|,
name|_REG0_
block|,
name|_REG0_
block|,
name|_REG0_
block|,
name|_REG0_
block|,
name|_REG0_
block|,
name|_REG0_
block|,
name|_REG0_
block|,
name|_REG0_
block|,
name|_NONE_
block|,
name|_null_
block|,
name|_NONE_
block|,
name|_PUSH_
block|,
name|_NONE_
block|,
name|_PUSH_
block|,
name|_null_
block|,
name|_PUSH_
block|,
name|_NONE_
block|,
name|_null_
block|,
name|_NONE_
block|,
name|_REG0_
block|,
name|_NONE_
block|,
name|_REG0_
block|,
name|_NONE_
block|,
name|_REG0_
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|load_store_instr
parameter_list|(
name|char
name|type
parameter_list|)
block|{
name|FPU_REG
modifier|*
name|pop_ptr
decl_stmt|;
comment|/* We need a version of FPU_st0_ptr which 				 * won't change. */
name|pop_ptr
operator|=
name|NULL
expr_stmt|;
comment|/* Initialized just to stop compiler warnings. */
switch|switch
condition|(
name|type_table
index|[
operator|(
name|int
operator|)
operator|(
name|unsigned
operator|)
name|type
index|]
condition|)
block|{
case|case
name|_NONE_
case|:
break|break;
case|case
name|_REG0_
case|:
name|pop_ptr
operator|=
operator|&
name|st
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Some of these instructions pop 					 * after storing */
name|FPU_st0_ptr
operator|=
name|pop_ptr
expr_stmt|;
comment|/* Set the global variables. */
name|FPU_st0_tag
operator|=
name|FPU_st0_ptr
operator|->
name|tag
expr_stmt|;
break|break;
case|case
name|_PUSH_
case|:
block|{
name|pop_ptr
operator|=
operator|&
name|st
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|pop_ptr
operator|->
name|tag
operator|!=
name|TW_Empty
condition|)
block|{
name|stack_overflow
argument_list|()
expr_stmt|;
return|return;
block|}
name|top
operator|--
expr_stmt|;
block|}
break|break;
case|case
name|_null_
case|:
name|Un_impl
argument_list|()
expr_stmt|;
return|return;
ifdef|#
directive|ifdef
name|PARANOID
default|default:
return|return
name|EXCEPTION
argument_list|(
name|EX_INTERNAL
argument_list|)
return|;
endif|#
directive|endif
comment|/* PARANOID */
block|}
switch|switch
condition|(
name|type
condition|)
block|{
case|case
literal|000
case|:
comment|/* fld m32real */
name|reg_load_single
argument_list|()
expr_stmt|;
name|setcc
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Clear the SW_C1 bit, "other bits undefined" */
name|reg_move
argument_list|(
operator|&
name|FPU_loaded_data
argument_list|,
name|pop_ptr
argument_list|)
expr_stmt|;
break|break;
case|case
literal|001
case|:
comment|/* fild m32int */
name|reg_load_int32
argument_list|()
expr_stmt|;
name|setcc
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Clear the SW_C1 bit, "other bits undefined" */
name|reg_move
argument_list|(
operator|&
name|FPU_loaded_data
argument_list|,
name|pop_ptr
argument_list|)
expr_stmt|;
break|break;
case|case
literal|002
case|:
comment|/* fld m64real */
name|reg_load_double
argument_list|()
expr_stmt|;
name|setcc
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Clear the SW_C1 bit, "other bits undefined" */
name|reg_move
argument_list|(
operator|&
name|FPU_loaded_data
argument_list|,
name|pop_ptr
argument_list|)
expr_stmt|;
break|break;
case|case
literal|003
case|:
comment|/* fild m16int */
name|reg_load_int16
argument_list|()
expr_stmt|;
name|setcc
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Clear the SW_C1 bit, "other bits undefined" */
name|reg_move
argument_list|(
operator|&
name|FPU_loaded_data
argument_list|,
name|pop_ptr
argument_list|)
expr_stmt|;
break|break;
case|case
literal|010
case|:
comment|/* fst m32real */
name|reg_store_single
argument_list|()
expr_stmt|;
break|break;
case|case
literal|011
case|:
comment|/* fist m32int */
name|reg_store_int32
argument_list|()
expr_stmt|;
break|break;
case|case
literal|012
case|:
comment|/* fst m64real */
name|reg_store_double
argument_list|()
expr_stmt|;
break|break;
case|case
literal|013
case|:
comment|/* fist m16int */
name|reg_store_int16
argument_list|()
expr_stmt|;
break|break;
case|case
literal|014
case|:
comment|/* fstp m32real */
if|if
condition|(
name|reg_store_single
argument_list|()
condition|)
name|pop_0
argument_list|()
expr_stmt|;
comment|/* pop only if the number was actually stored 				 * (see the 80486 manual p16-28) */
break|break;
case|case
literal|015
case|:
comment|/* fistp m32int */
if|if
condition|(
name|reg_store_int32
argument_list|()
condition|)
name|pop_0
argument_list|()
expr_stmt|;
comment|/* pop only if the number was actually stored 				 * (see the 80486 manual p16-28) */
break|break;
case|case
literal|016
case|:
comment|/* fstp m64real */
if|if
condition|(
name|reg_store_double
argument_list|()
condition|)
name|pop_0
argument_list|()
expr_stmt|;
comment|/* pop only if the number was actually stored 				 * (see the 80486 manual p16-28) */
break|break;
case|case
literal|017
case|:
comment|/* fistp m16int */
if|if
condition|(
name|reg_store_int16
argument_list|()
condition|)
name|pop_0
argument_list|()
expr_stmt|;
comment|/* pop only if the number was actually stored 				 * (see the 80486 manual p16-28) */
break|break;
case|case
literal|020
case|:
comment|/* fldenv  m14/28byte */
name|fldenv
argument_list|()
expr_stmt|;
break|break;
case|case
literal|022
case|:
comment|/* frstor m94/108byte */
name|frstor
argument_list|()
expr_stmt|;
break|break;
case|case
literal|023
case|:
comment|/* fbld m80dec */
name|reg_load_bcd
argument_list|()
expr_stmt|;
name|setcc
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Clear the SW_C1 bit, "other bits undefined" */
name|reg_move
argument_list|(
operator|&
name|FPU_loaded_data
argument_list|,
name|pop_ptr
argument_list|)
expr_stmt|;
break|break;
case|case
literal|024
case|:
comment|/* fldcw */
name|REENTRANT_CHECK
argument_list|(
name|OFF
argument_list|)
expr_stmt|;
name|control_word
operator|=
name|fusword
argument_list|(
operator|(
name|unsigned
name|short
operator|*
operator|)
name|FPU_data_address
argument_list|)
expr_stmt|;
name|REENTRANT_CHECK
argument_list|(
name|ON
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|NO_UNDERFLOW_TRAP
if|if
condition|(
operator|!
operator|(
name|control_word
operator|&
name|EX_Underflow
operator|)
condition|)
block|{
name|control_word
operator||=
name|EX_Underflow
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* We want no net effect: */
name|FPU_data_address
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
name|intptr_t
operator|)
name|data_operand_offset
expr_stmt|;
name|FPU_entry_eip
operator|=
name|ip_offset
expr_stmt|;
comment|/* We want no net effect */
break|break;
case|case
literal|025
case|:
comment|/* fld m80real */
name|reg_load_extended
argument_list|()
expr_stmt|;
name|setcc
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Clear the SW_C1 bit, "other bits undefined" */
name|reg_move
argument_list|(
operator|&
name|FPU_loaded_data
argument_list|,
name|pop_ptr
argument_list|)
expr_stmt|;
break|break;
case|case
literal|027
case|:
comment|/* fild m64int */
name|reg_load_int64
argument_list|()
expr_stmt|;
name|setcc
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Clear the SW_C1 bit, "other bits undefined" */
name|reg_move
argument_list|(
operator|&
name|FPU_loaded_data
argument_list|,
name|pop_ptr
argument_list|)
expr_stmt|;
break|break;
case|case
literal|030
case|:
comment|/* fstenv  m14/28byte */
name|fstenv
argument_list|()
expr_stmt|;
comment|/* We want no net effect: */
name|FPU_data_address
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
name|intptr_t
operator|)
name|data_operand_offset
expr_stmt|;
name|FPU_entry_eip
operator|=
name|ip_offset
expr_stmt|;
comment|/* We want no net effect */
break|break;
case|case
literal|032
case|:
comment|/* fsave */
name|fsave
argument_list|()
expr_stmt|;
comment|/* We want no net effect: */
name|FPU_data_address
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
name|intptr_t
operator|)
name|data_operand_offset
expr_stmt|;
name|FPU_entry_eip
operator|=
name|ip_offset
expr_stmt|;
comment|/* We want no net effect */
break|break;
case|case
literal|033
case|:
comment|/* fbstp m80dec */
if|if
condition|(
name|reg_store_bcd
argument_list|()
condition|)
name|pop_0
argument_list|()
expr_stmt|;
comment|/* pop only if the number was actually stored 				 * (see the 80486 manual p16-28) */
break|break;
case|case
literal|034
case|:
comment|/* fstcw m16int */
name|REENTRANT_CHECK
argument_list|(
name|OFF
argument_list|)
expr_stmt|;
comment|/*		    verify_area(VERIFY_WRITE, FPU_data_address, 2);*/
name|susword
argument_list|(
operator|(
name|short
operator|*
operator|)
name|FPU_data_address
argument_list|,
name|control_word
argument_list|)
expr_stmt|;
name|REENTRANT_CHECK
argument_list|(
name|ON
argument_list|)
expr_stmt|;
comment|/* We want no net effect: */
name|FPU_data_address
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
name|intptr_t
operator|)
name|data_operand_offset
expr_stmt|;
name|FPU_entry_eip
operator|=
name|ip_offset
expr_stmt|;
comment|/* We want no net effect */
break|break;
case|case
literal|035
case|:
comment|/* fstp m80real */
if|if
condition|(
name|reg_store_extended
argument_list|()
condition|)
name|pop_0
argument_list|()
expr_stmt|;
comment|/* pop only if the number was actually stored 				 * (see the 80486 manual p16-28) */
break|break;
case|case
literal|036
case|:
comment|/* fstsw m2byte */
name|status_word
operator|&=
operator|~
name|SW_Top
expr_stmt|;
name|status_word
operator||=
operator|(
name|top
operator|&
literal|7
operator|)
operator|<<
name|SW_Top_Shift
expr_stmt|;
name|REENTRANT_CHECK
argument_list|(
name|OFF
argument_list|)
expr_stmt|;
comment|/*		    verify_area(VERIFY_WRITE, FPU_data_address, 2);*/
name|susword
argument_list|(
operator|(
name|short
operator|*
operator|)
name|FPU_data_address
argument_list|,
name|status_word
argument_list|)
expr_stmt|;
name|REENTRANT_CHECK
argument_list|(
name|ON
argument_list|)
expr_stmt|;
comment|/* We want no net effect: */
name|FPU_data_address
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
name|intptr_t
operator|)
name|data_operand_offset
expr_stmt|;
name|FPU_entry_eip
operator|=
name|ip_offset
expr_stmt|;
comment|/* We want no net effect */
break|break;
case|case
literal|037
case|:
comment|/* fistp m64int */
if|if
condition|(
name|reg_store_int64
argument_list|()
condition|)
name|pop_0
argument_list|()
expr_stmt|;
comment|/* pop only if the number was actually stored 				 * (see the 80486 manual p16-28) */
break|break;
block|}
block|}
end_function

end_unit

