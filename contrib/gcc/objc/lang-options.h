begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Switch definitions for the GNU compiler for the Objective-C language.    Copyright (C) 2000 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This is the contribution to the `documented_lang_options' array in    toplev.c for Objective-C.  */
end_comment

begin_macro
name|DEFINE_LANG_NAME
argument_list|(
literal|"Objective C"
argument_list|)
end_macro

begin_block
block|{
literal|"-gen-decls"
operator|,
name|N_
argument_list|(
literal|"Dump decls to a .decl file"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fgnu-runtime"
operator|,
name|N_
argument_list|(
literal|"Generate code for GNU runtime environment"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-gnu-runtime"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fnext-runtime"
operator|,
name|N_
argument_list|(
literal|"Generate code for NeXT runtime environment"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-next-runtime"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wselector"
operator|,
name|N_
argument_list|(
literal|"Warn if a selector has multiple methods"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wno-selector"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wprotocol"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wno-protocol"
operator|,
name|N_
argument_list|(
literal|"Do not warn if inherited methods are unimplemented"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-print-objc-runtime-info"
operator|,
name|N_
argument_list|(
literal|"Generate C header of platform specific features"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fconstant-string-class"
operator|,
name|N_
argument_list|(
literal|"Specify the name of the class for constant strings"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

end_unit

