begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* obj-bfd-sunos.c    Copyright (C) 1987, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"as.h"
end_include

begin_decl_stmt
specifier|static
specifier|const
name|short
name|seg_N_TYPE
index|[]
init|=
block|{
name|N_ABS
block|,
name|N_TEXT
block|,
name|N_DATA
block|,
name|N_BSS
block|,
name|N_UNDF
block|,
comment|/* unknown */
name|N_UNDF
block|,
comment|/* absent */
name|N_UNDF
block|,
comment|/* pass1 */
name|N_UNDF
block|,
comment|/* error */
name|N_UNDF
block|,
comment|/* bignum/flonum */
name|N_UNDF
block|,
comment|/* difference */
name|N_REGISTER
block|,
comment|/* register */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|segT
name|N_TYPE_seg
index|[
name|N_TYPE
operator|+
literal|2
index|]
init|=
block|{
comment|/* N_TYPE == 0x1E = 32-2 */
name|SEG_UNKNOWN
block|,
comment|/* N_UNDF == 0 */
name|SEG_GOOF
block|,
name|SEG_ABSOLUTE
block|,
comment|/* N_ABS == 2 */
name|SEG_GOOF
block|,
name|SEG_TEXT
block|,
comment|/* N_TEXT == 4 */
name|SEG_GOOF
block|,
name|SEG_DATA
block|,
comment|/* N_DATA == 6 */
name|SEG_GOOF
block|,
name|SEG_BSS
block|,
comment|/* N_BSS == 8 */
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_GOOF
block|,
name|SEG_REGISTER
block|,
comment|/* dummy N_REGISTER for regs = 30 */
name|SEG_GOOF
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|obj_symbol_new_hook
parameter_list|(
name|symbolP
parameter_list|)
name|symbolS
modifier|*
name|symbolP
decl_stmt|;
block|{
return|return;
block|}
end_function

begin_comment
comment|/* obj_symbol_new_hook() */
end_comment

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of obj-bfd-sunos.c */
end_comment

end_unit

