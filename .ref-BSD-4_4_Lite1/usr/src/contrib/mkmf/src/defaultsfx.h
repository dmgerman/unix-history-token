begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1985, 1991 Peter J. Nicklin.  * Copyright (c) 1991 Version Technology.  * All Rights Reserved.  *  * $License: VT.1.1 $  * Redistribution and use in source and binary forms,  with or without  * modification,  are permitted provided that the following conditions  * are met:  (1) Redistributions of source code must retain the  above  * copyright  notice,  this  list  of  conditions  and  the  following  * disclaimer.  (2) Redistributions in binary form must reproduce  the  * above  copyright notice,  this list of conditions and the following  * disclaimer in the  documentation  and/or other  materials  provided  * with  the  distribution.  (3) All advertising materials  mentioning  * features or  use  of  this  software  must  display  the  following  * acknowledgement:  ``This  product  includes  software  developed by  * Version Technology.''  Neither the name of Version  Technology  nor  * the  name  of  Peter J. Nicklin  may  be used to endorse or promote  * products derived from this software without specific prior  written  * permission.  *  * THIS SOFTWARE IS PROVIDED BY VERSION TECHNOLOGY ``AS IS''  AND  ANY  * EXPRESS OR IMPLIED WARRANTIES,  INCLUDING,  BUT NOT LIMITED TO, THE  * IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  VERSION  TECHNOLOGY  BE  * LIABLE  FOR ANY DIRECT,  INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY,  * OR  CONSEQUENTIAL DAMAGES   (INCLUDING,   BUT   NOT   LIMITED   TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY  * OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT LIABILITY,  OR  TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING  IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE,  EVEN  IF  ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * Report problems and direct questions to nicklin@netcom.com  *  * $Header: defaultsfx.h,v 4.3 91/11/25 19:45:47 nicklin Exp $  *  * Default suffixes  *  * Author: Peter J. Nicklin  */
end_comment

begin_expr_stmt
literal|".c"
operator|,
name|SFXSRC
operator|,
name|INCLUDE_C
operator|,
literal|"C"
operator|,
comment|/* C */
literal|".cc"
operator|,
name|SFXSRC
operator|,
name|INCLUDE_CXX
operator|,
literal|"C++"
operator|,
comment|/* C++ */
literal|".cxx"
operator|,
name|SFXSRC
operator|,
name|INCLUDE_CXX
operator|,
literal|"C++"
operator|,
comment|/* C++ */
literal|".cpp"
operator|,
name|SFXSRC
operator|,
name|INCLUDE_CXX
operator|,
literal|"C++"
operator|,
comment|/* C++ */
literal|".C"
operator|,
name|SFXSRC
operator|,
name|INCLUDE_CXX
operator|,
literal|"C++"
operator|,
comment|/* C++ */
literal|".F"
operator|,
name|SFXSRC
operator|,
name|INCLUDE_FORTRAN
operator|,
literal|"F"
operator|,
comment|/* Fortran */
literal|".f"
operator|,
name|SFXSRC
operator|,
name|INCLUDE_FORTRAN
operator|,
literal|"F"
operator|,
comment|/* Fortran */
literal|".h"
operator|,
name|SFXHEAD
operator|,
name|INCLUDE_NONE
operator|,
name|NULL
operator|,
comment|/* header */
literal|".hxx"
operator|,
name|SFXHEAD
operator|,
name|INCLUDE_NONE
operator|,
name|NULL
operator|,
comment|/* header */
literal|".hpp"
operator|,
name|SFXHEAD
operator|,
name|INCLUDE_NONE
operator|,
name|NULL
operator|,
comment|/* header */
literal|".H"
operator|,
name|SFXHEAD
operator|,
name|INCLUDE_NONE
operator|,
name|NULL
operator|,
comment|/* header */
literal|".i"
operator|,
name|SFXHEAD
operator|,
name|INCLUDE_NONE
operator|,
name|NULL
operator|,
comment|/* Pascal include */
literal|".l"
operator|,
name|SFXSRC
operator|,
name|INCLUDE_C
operator|,
literal|"C"
operator|,
comment|/* Lex */
literal|".o"
operator|,
name|SFXOBJ
operator|,
name|INCLUDE_NONE
operator|,
name|NULL
operator|,
comment|/* object */
literal|".p"
operator|,
name|SFXSRC
operator|,
name|INCLUDE_PASCAL
operator|,
literal|"P"
operator|,
comment|/* Pascal */
literal|".r"
operator|,
name|SFXSRC
operator|,
name|INCLUDE_FORTRAN
operator|,
literal|"F"
operator|,
comment|/* Ratfor */
literal|".s"
operator|,
name|SFXSRC
operator|,
name|INCLUDE_NONE
operator|,
name|NULL
operator|,
comment|/* Assembler */
literal|".y"
operator|,
name|SFXSRC
operator|,
name|INCLUDE_C
operator|,
literal|"C"
operator|,
comment|/* Yacc */
name|NULL
operator|,
name|SFXNULL
operator|,
name|INCLUDE_NONE
operator|,
name|NULL
end_expr_stmt

begin_comment
comment|/* mandatory last line */
end_comment

end_unit

