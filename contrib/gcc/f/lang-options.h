begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* lang-options.h file for Fortran    Copyright (C) 1995-1998 Free Software Foundation, Inc.    Contributed by James Craig Burley (burley@gnu.org).  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This is the contribution to the `lang_options' array in gcc.c for    g77.  */
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
literal|"Print g77-specific compiler version info, run internal tests"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fnull-version"
operator|,
literal|""
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
literal|"Program is written in typical FORTRAN 66 dialect"
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
literal|"Program is written in typical Unix f77 dialect"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-f77"
operator|,
literal|"Program does not use Unix-f77 dialectal features"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ff90"
operator|,
literal|"Program is written in Fortran-90-ish dialect"
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
literal|"Treat local vars and COMMON blocks as if they were named in SAVE statements"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fdollar-ok"
operator|,
literal|"Allow $ in symbol names"
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
literal|"f2c-compatible code need not be generated"
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
literal|"Unsupported; do not generate libf2c-calling code"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ffree-form"
operator|,
literal|"Program is written in Fortran-90-ish free form"
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
literal|"Warn about use of (only a few for now) Fortran extensions"
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
literal|"Program is written in VXT (Digital-like) FORTRAN"
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
literal|"-fugly"
operator|,
literal|"Obsolete; allow certain ugly features"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-ugly"
operator|,
literal|""
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
literal|"Hollerith and typeless constants not passed as arguments"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fugly-assign"
operator|,
literal|"Allow ordinary copying of ASSIGN'ed vars"
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
literal|"Dummy array dimensioned to (1) is assumed-size"
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
literal|"Trailing comma in procedure call denotes null argument"
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
literal|"Allow REAL(Z) and AIMAG(Z) given DOUBLE COMPLEX Z"
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
literal|"Initialization via DATA and PARAMETER is type-compatible"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fugly-logint"
operator|,
literal|"Allow INTEGER and LOGICAL interchangeability"
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
literal|"Print internal debugging-related info"
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
literal|"Initialize local vars and arrays to zero"
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
literal|"Backslashes in character/hollerith constants not special (C-style)"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-femulate-complex"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-emulate-complex"
operator|,
literal|"Have compiler back end cope with COMPLEX arithmetic"
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
literal|"Disable the appending of underscores to externals"
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
literal|"Never append a second underscore to externals"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fintrin-case-initcap"
operator|,
literal|"Intrinsics spelled as e.g. SqRt"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fintrin-case-upper"
operator|,
literal|"Intrinsics in uppercase"
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
literal|"Intrinsics letters in arbitrary cases"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fmatch-case-initcap"
operator|,
literal|"Language keywords spelled as e.g. IOStat"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fmatch-case-upper"
operator|,
literal|"Language keywords in uppercase"
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
literal|"Language keyword letters in arbitrary cases"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fsource-case-upper"
operator|,
literal|"Internally convert most source to uppercase"
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
literal|"Internally preserve source case"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fsymbol-case-initcap"
operator|,
literal|"Symbol names spelled in mixed case"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fsymbol-case-upper"
operator|,
literal|"Symbol names in uppercase"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fsymbol-case-lower"
operator|,
literal|"Symbol names in lowercase"
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
literal|"Program written in uppercase"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fcase-strict-lower"
operator|,
literal|"Program written in lowercase"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fcase-initcap"
operator|,
literal|"Program written in strict mixed-case"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fcase-upper"
operator|,
literal|"Compile as if program written in uppercase"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fcase-lower"
operator|,
literal|"Compile as if program written in lowercase"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fcase-preserve"
operator|,
literal|"Preserve all spelling (case) used in program"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fbadu77-intrinsics-delete"
operator|,
literal|"Delete libU77 intrinsics with bad interfaces"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fbadu77-intrinsics-disable"
operator|,
literal|"Disable libU77 intrinsics with bad interfaces"
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
literal|"Hide libU77 intrinsics with bad interfaces"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ff2c-intrinsics-delete"
operator|,
literal|"Delete non-FORTRAN-77 intrinsics f2c supports"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ff2c-intrinsics-disable"
operator|,
literal|"Disable non-FORTRAN-77 intrinsics f2c supports"
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
literal|"Hide non-FORTRAN-77 intrinsics f2c supports"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ff90-intrinsics-delete"
operator|,
literal|"Delete non-FORTRAN-77 intrinsics F90 supports"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ff90-intrinsics-disable"
operator|,
literal|"Disable non-FORTRAN-77 intrinsics F90 supports"
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
literal|"Hide non-FORTRAN-77 intrinsics F90 supports"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fgnu-intrinsics-delete"
operator|,
literal|"Delete non-FORTRAN-77 intrinsics g77 supports"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fgnu-intrinsics-disable"
operator|,
literal|"Disable non-FORTRAN 77 intrinsics F90 supports"
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
literal|"Hide non-FORTRAN 77 intrinsics F90 supports"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fmil-intrinsics-delete"
operator|,
literal|"Delete MIL-STD 1753 intrinsics"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fmil-intrinsics-disable"
operator|,
literal|"Disable MIL-STD 1753 intrinsics"
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
literal|"Hide MIL-STD 1753 intrinsics"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-funix-intrinsics-delete"
operator|,
literal|"Delete libU77 intrinsics"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-funix-intrinsics-disable"
operator|,
literal|"Disable libU77 intrinsics"
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
literal|"Hide libU77 intrinsics"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fvxt-intrinsics-delete"
operator|,
literal|"Delete non-FORTRAN-77 intrinsics VXT FORTRAN supports"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fvxt-intrinsics-disable"
operator|,
literal|"Disable non-FORTRAN-77 intrinsics VXT FORTRAN supports"
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
literal|"Hide non-FORTRAN-77 intrinsics VXT FORTRAN supports"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fzeros"
operator|,
literal|"Treat initial values of 0 like non-zero values"
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
literal|"Emit special debugging information for COMMON and EQUIVALENCE"
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
literal|"Take at least one trip through each iterative DO loop"
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
literal|"Print names of program units as they are compiled"
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
literal|"Disable fatal diagnostics about inter-procedural problems"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ftypeless-boz"
operator|,
literal|"Make prefix-radix non-decimal constants be typeless"
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
literal|"Disable warnings about inter-procedural problems"
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
literal|"Warn about constructs with surprising meanings"
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
literal|"Add a directory for INCLUDE searching"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ffixed-line-length-"
operator|,
literal|"Set the maximum line length"
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

