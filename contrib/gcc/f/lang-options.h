begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* lang-options.h file for Fortran    Copyright (C) 1995, 1996, 1997, 1998, 1999, 2000 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This is the contribution to the `documented_lang_options' array in    toplev.c for g77.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_comment
comment|/* To be consistent with lang-specs.h.  Maybe avoid 		   overflowing some old compiler's tables, etc. */
end_comment

begin_macro
name|DEFINE_LANG_NAME
argument_list|(
literal|"Fortran"
argument_list|)
end_macro

begin_block
block|{
literal|"-fversion"
operator|,
name|N_
argument_list|(
literal|"Print g77-specific compiler version info, run internal tests"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_comment
comment|/*"-fident",*/
end_comment

begin_comment
comment|/*"-fno-ident",*/
end_comment

begin_block
block|{
literal|"-ff66"
operator|,
name|N_
argument_list|(
literal|"Program is written in typical FORTRAN 66 dialect"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-f66"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ff77"
operator|,
name|N_
argument_list|(
literal|"Program is written in typical Unix f77 dialect"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-f77"
operator|,
name|N_
argument_list|(
literal|"Program does not use Unix-f77 dialectal features"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ff90"
operator|,
name|N_
argument_list|(
literal|"Program is written in Fortran-90-ish dialect"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-f90"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fautomatic"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-automatic"
operator|,
name|N_
argument_list|(
literal|"Treat local vars and COMMON blocks as if they were named in SAVE statements"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fdollar-ok"
operator|,
name|N_
argument_list|(
literal|"Allow $ in symbol names"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-dollar-ok"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ff2c"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-f2c"
operator|,
name|N_
argument_list|(
literal|"f2c-compatible code need not be generated"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ff2c-library"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-f2c-library"
operator|,
name|N_
argument_list|(
literal|"Unsupported; do not generate libf2c-calling code"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fflatten-arrays"
operator|,
name|N_
argument_list|(
literal|"Unsupported; affects code-generation of arrays"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-flatten-arrays"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ffree-form"
operator|,
name|N_
argument_list|(
literal|"Program is written in Fortran-90-ish free form"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-free-form"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ffixed-form"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-fixed-form"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fpedantic"
operator|,
name|N_
argument_list|(
literal|"Warn about use of (only a few for now) Fortran extensions"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-pedantic"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fvxt"
operator|,
name|N_
argument_list|(
literal|"Program is written in VXT (Digital-like) FORTRAN"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-vxt"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-ugly"
operator|,
name|N_
argument_list|(
literal|"Disallow all ugly features"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fugly-args"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-ugly-args"
operator|,
name|N_
argument_list|(
literal|"Hollerith and typeless constants not passed as arguments"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fugly-assign"
operator|,
name|N_
argument_list|(
literal|"Allow ordinary copying of ASSIGN'ed vars"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-ugly-assign"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fugly-assumed"
operator|,
name|N_
argument_list|(
literal|"Dummy array dimensioned to (1) is assumed-size"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-ugly-assumed"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fugly-comma"
operator|,
name|N_
argument_list|(
literal|"Trailing comma in procedure call denotes null argument"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-ugly-comma"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fugly-complex"
operator|,
name|N_
argument_list|(
literal|"Allow REAL(Z) and AIMAG(Z) given DOUBLE COMPLEX Z"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-ugly-complex"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fugly-init"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-ugly-init"
operator|,
name|N_
argument_list|(
literal|"Initialization via DATA and PARAMETER is type-compatible"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fugly-logint"
operator|,
name|N_
argument_list|(
literal|"Allow INTEGER and LOGICAL interchangeability"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-ugly-logint"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fxyzzy"
operator|,
name|N_
argument_list|(
literal|"Print internal debugging-related info"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-xyzzy"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-finit-local-zero"
operator|,
name|N_
argument_list|(
literal|"Initialize local vars and arrays to zero"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-init-local-zero"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fbackslash"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-backslash"
operator|,
name|N_
argument_list|(
literal|"Backslashes in character/hollerith constants not special (C-style)"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-femulate-complex"
operator|,
name|N_
argument_list|(
literal|"Have front end emulate COMPLEX arithmetic to avoid bugs"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-emulate-complex"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-funderscoring"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-underscoring"
operator|,
name|N_
argument_list|(
literal|"Disable the appending of underscores to externals"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fsecond-underscore"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-second-underscore"
operator|,
name|N_
argument_list|(
literal|"Never append a second underscore to externals"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fintrin-case-initcap"
operator|,
name|N_
argument_list|(
literal|"Intrinsics spelled as e.g. SqRt"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fintrin-case-upper"
operator|,
name|N_
argument_list|(
literal|"Intrinsics in uppercase"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fintrin-case-lower"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fintrin-case-any"
operator|,
name|N_
argument_list|(
literal|"Intrinsics letters in arbitrary cases"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fmatch-case-initcap"
operator|,
name|N_
argument_list|(
literal|"Language keywords spelled as e.g. IOStat"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fmatch-case-upper"
operator|,
name|N_
argument_list|(
literal|"Language keywords in uppercase"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fmatch-case-lower"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fmatch-case-any"
operator|,
name|N_
argument_list|(
literal|"Language keyword letters in arbitrary cases"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fsource-case-upper"
operator|,
name|N_
argument_list|(
literal|"Internally convert most source to uppercase"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fsource-case-lower"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fsource-case-preserve"
operator|,
name|N_
argument_list|(
literal|"Internally preserve source case"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fsymbol-case-initcap"
operator|,
name|N_
argument_list|(
literal|"Symbol names spelled in mixed case"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fsymbol-case-upper"
operator|,
name|N_
argument_list|(
literal|"Symbol names in uppercase"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fsymbol-case-lower"
operator|,
name|N_
argument_list|(
literal|"Symbol names in lowercase"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fsymbol-case-any"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fcase-strict-upper"
operator|,
name|N_
argument_list|(
literal|"Program written in uppercase"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fcase-strict-lower"
operator|,
name|N_
argument_list|(
literal|"Program written in lowercase"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fcase-initcap"
operator|,
name|N_
argument_list|(
literal|"Program written in strict mixed-case"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fcase-upper"
operator|,
name|N_
argument_list|(
literal|"Compile as if program written in uppercase"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fcase-lower"
operator|,
name|N_
argument_list|(
literal|"Compile as if program written in lowercase"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fcase-preserve"
operator|,
name|N_
argument_list|(
literal|"Preserve all spelling (case) used in program"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fbadu77-intrinsics-delete"
operator|,
name|N_
argument_list|(
literal|"Delete libU77 intrinsics with bad interfaces"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fbadu77-intrinsics-disable"
operator|,
name|N_
argument_list|(
literal|"Disable libU77 intrinsics with bad interfaces"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fbadu77-intrinsics-enable"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fbadu77-intrinsics-hide"
operator|,
name|N_
argument_list|(
literal|"Hide libU77 intrinsics with bad interfaces"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ff2c-intrinsics-delete"
operator|,
name|N_
argument_list|(
literal|"Delete non-FORTRAN-77 intrinsics f2c supports"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ff2c-intrinsics-disable"
operator|,
name|N_
argument_list|(
literal|"Disable non-FORTRAN-77 intrinsics f2c supports"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ff2c-intrinsics-enable"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ff2c-intrinsics-hide"
operator|,
name|N_
argument_list|(
literal|"Hide non-FORTRAN-77 intrinsics f2c supports"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ff90-intrinsics-delete"
operator|,
name|N_
argument_list|(
literal|"Delete non-FORTRAN-77 intrinsics F90 supports"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ff90-intrinsics-disable"
operator|,
name|N_
argument_list|(
literal|"Disable non-FORTRAN-77 intrinsics F90 supports"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ff90-intrinsics-enable"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ff90-intrinsics-hide"
operator|,
name|N_
argument_list|(
literal|"Hide non-FORTRAN-77 intrinsics F90 supports"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fgnu-intrinsics-delete"
operator|,
name|N_
argument_list|(
literal|"Delete non-FORTRAN-77 intrinsics g77 supports"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fgnu-intrinsics-disable"
operator|,
name|N_
argument_list|(
literal|"Disable non-FORTRAN 77 intrinsics F90 supports"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fgnu-intrinsics-enable"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fgnu-intrinsics-hide"
operator|,
name|N_
argument_list|(
literal|"Hide non-FORTRAN 77 intrinsics F90 supports"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fmil-intrinsics-delete"
operator|,
name|N_
argument_list|(
literal|"Delete MIL-STD 1753 intrinsics"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fmil-intrinsics-disable"
operator|,
name|N_
argument_list|(
literal|"Disable MIL-STD 1753 intrinsics"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fmil-intrinsics-enable"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fmil-intrinsics-hide"
operator|,
name|N_
argument_list|(
literal|"Hide MIL-STD 1753 intrinsics"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-funix-intrinsics-delete"
operator|,
name|N_
argument_list|(
literal|"Delete libU77 intrinsics"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-funix-intrinsics-disable"
operator|,
name|N_
argument_list|(
literal|"Disable libU77 intrinsics"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-funix-intrinsics-enable"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-funix-intrinsics-hide"
operator|,
name|N_
argument_list|(
literal|"Hide libU77 intrinsics"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fvxt-intrinsics-delete"
operator|,
name|N_
argument_list|(
literal|"Delete non-FORTRAN-77 intrinsics VXT FORTRAN supports"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fvxt-intrinsics-disable"
operator|,
name|N_
argument_list|(
literal|"Disable non-FORTRAN-77 intrinsics VXT FORTRAN supports"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fvxt-intrinsics-enable"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fvxt-intrinsics-hide"
operator|,
name|N_
argument_list|(
literal|"Hide non-FORTRAN-77 intrinsics VXT FORTRAN supports"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fzeros"
operator|,
name|N_
argument_list|(
literal|"Treat initial values of 0 like non-zero values"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-zeros"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fdebug-kludge"
operator|,
name|N_
argument_list|(
literal|"Emit special debugging information for COMMON and EQUIVALENCE (disabled)"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-debug-kludge"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fonetrip"
operator|,
name|N_
argument_list|(
literal|"Take at least one trip through each iterative DO loop"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-onetrip"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fsilent"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-silent"
operator|,
name|N_
argument_list|(
literal|"Print names of program units as they are compiled"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fglobals"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-globals"
operator|,
name|N_
argument_list|(
literal|"Disable fatal diagnostics about inter-procedural problems"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ftypeless-boz"
operator|,
name|N_
argument_list|(
literal|"Make prefix-radix non-decimal constants be typeless"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-typeless-boz"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fbounds-check"
operator|,
name|N_
argument_list|(
literal|"Generate code to check subscript and substring bounds"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-bounds-check"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ffortran-bounds-check"
operator|,
name|N_
argument_list|(
literal|"Fortran-specific form of -fbounds-check"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-fortran-bounds-check"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wglobals"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wno-globals"
operator|,
name|N_
argument_list|(
literal|"Disable warnings about inter-procedural problems"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_comment
comment|/*"-Wimplicit",*/
end_comment

begin_comment
comment|/*"-Wno-implicit",*/
end_comment

begin_block
block|{
literal|"-Wsurprising"
operator|,
name|N_
argument_list|(
literal|"Warn about constructs with surprising meanings"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wno-surprising"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_comment
comment|/*"-Wall",*/
end_comment

begin_comment
comment|/* Prefix options.  */
end_comment

begin_block
block|{
literal|"-I"
operator|,
name|N_
argument_list|(
literal|"Add a directory for INCLUDE searching"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ffixed-line-length-"
operator|,
name|N_
argument_list|(
literal|"Set the maximum line length"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_endif
endif|#
directive|endif
end_endif

end_unit

