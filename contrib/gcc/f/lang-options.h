begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* lang-options.h file for Fortran    Copyright (C) 1995-1998 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_comment
comment|/* Use of FTNOPT makes tracking changes between FSF-g77 and egcs-g77    easier, since FSF-gcc doesn't support doc strings.  */
end_comment

begin_define
define|#
directive|define
name|FTNOPT
parameter_list|(
name|opt
parameter_list|,
name|doc
parameter_list|)
value|{ opt, doc },
end_define

begin_macro
name|FTNOPT
argument_list|(
literal|"-fversion"
argument_list|,
literal|"Print g77-specific compiler version info, run internal tests"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fnull-version"
argument_list|,
literal|""
argument_list|)
end_macro

begin_comment
comment|/*"-fident",*/
end_comment

begin_comment
comment|/*"-fno-ident",*/
end_comment

begin_macro
name|FTNOPT
argument_list|(
literal|"-ff66"
argument_list|,
literal|"Program is written in typical FORTRAN 66 dialect"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-f66"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-ff77"
argument_list|,
literal|"Program is written in typical Unix f77 dialect"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-f77"
argument_list|,
literal|"Program does not use Unix-f77 dialectal features"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-ff90"
argument_list|,
literal|"Program is written in Fortran-90-ish dialect"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-f90"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fautomatic"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-automatic"
argument_list|,
literal|"Treat local vars and COMMON blocks as if they were named in SAVE statements"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fdollar-ok"
argument_list|,
literal|"Allow $ in symbol names"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-dollar-ok"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-ff2c"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-f2c"
argument_list|,
literal|"f2c-compatible code need not be generated"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-ff2c-library"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-f2c-library"
argument_list|,
literal|"Unsupported; do not generate libf2c-calling code"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fflatten-arrays"
argument_list|,
literal|"Unsupported; affects code-generation of arrays"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-flatten-arrays"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-ffree-form"
argument_list|,
literal|"Program is written in Fortran-90-ish free form"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-free-form"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-ffixed-form"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-fixed-form"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fpedantic"
argument_list|,
literal|"Warn about use of (only a few for now) Fortran extensions"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-pedantic"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fvxt"
argument_list|,
literal|"Program is written in VXT (Digital-like) FORTRAN"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-vxt"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-ugly"
argument_list|,
literal|"Disallow all ugly features"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fugly-args"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-ugly-args"
argument_list|,
literal|"Hollerith and typeless constants not passed as arguments"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fugly-assign"
argument_list|,
literal|"Allow ordinary copying of ASSIGN'ed vars"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-ugly-assign"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fugly-assumed"
argument_list|,
literal|"Dummy array dimensioned to (1) is assumed-size"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-ugly-assumed"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fugly-comma"
argument_list|,
literal|"Trailing comma in procedure call denotes null argument"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-ugly-comma"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fugly-complex"
argument_list|,
literal|"Allow REAL(Z) and AIMAG(Z) given DOUBLE COMPLEX Z"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-ugly-complex"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fugly-init"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-ugly-init"
argument_list|,
literal|"Initialization via DATA and PARAMETER is type-compatible"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fugly-logint"
argument_list|,
literal|"Allow INTEGER and LOGICAL interchangeability"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-ugly-logint"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fxyzzy"
argument_list|,
literal|"Print internal debugging-related info"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-xyzzy"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-finit-local-zero"
argument_list|,
literal|"Initialize local vars and arrays to zero"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-init-local-zero"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fbackslash"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-backslash"
argument_list|,
literal|"Backslashes in character/hollerith constants not special (C-style)"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-femulate-complex"
argument_list|,
literal|"Have front end emulate COMPLEX arithmetic to avoid bugs"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-emulate-complex"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-funderscoring"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-underscoring"
argument_list|,
literal|"Disable the appending of underscores to externals"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fsecond-underscore"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-second-underscore"
argument_list|,
literal|"Never append a second underscore to externals"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fintrin-case-initcap"
argument_list|,
literal|"Intrinsics spelled as e.g. SqRt"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fintrin-case-upper"
argument_list|,
literal|"Intrinsics in uppercase"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fintrin-case-lower"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fintrin-case-any"
argument_list|,
literal|"Intrinsics letters in arbitrary cases"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fmatch-case-initcap"
argument_list|,
literal|"Language keywords spelled as e.g. IOStat"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fmatch-case-upper"
argument_list|,
literal|"Language keywords in uppercase"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fmatch-case-lower"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fmatch-case-any"
argument_list|,
literal|"Language keyword letters in arbitrary cases"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fsource-case-upper"
argument_list|,
literal|"Internally convert most source to uppercase"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fsource-case-lower"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fsource-case-preserve"
argument_list|,
literal|"Internally preserve source case"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fsymbol-case-initcap"
argument_list|,
literal|"Symbol names spelled in mixed case"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fsymbol-case-upper"
argument_list|,
literal|"Symbol names in uppercase"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fsymbol-case-lower"
argument_list|,
literal|"Symbol names in lowercase"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fsymbol-case-any"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fcase-strict-upper"
argument_list|,
literal|"Program written in uppercase"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fcase-strict-lower"
argument_list|,
literal|"Program written in lowercase"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fcase-initcap"
argument_list|,
literal|"Program written in strict mixed-case"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fcase-upper"
argument_list|,
literal|"Compile as if program written in uppercase"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fcase-lower"
argument_list|,
literal|"Compile as if program written in lowercase"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fcase-preserve"
argument_list|,
literal|"Preserve all spelling (case) used in program"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fbadu77-intrinsics-delete"
argument_list|,
literal|"Delete libU77 intrinsics with bad interfaces"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fbadu77-intrinsics-disable"
argument_list|,
literal|"Disable libU77 intrinsics with bad interfaces"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fbadu77-intrinsics-enable"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fbadu77-intrinsics-hide"
argument_list|,
literal|"Hide libU77 intrinsics with bad interfaces"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-ff2c-intrinsics-delete"
argument_list|,
literal|"Delete non-FORTRAN-77 intrinsics f2c supports"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-ff2c-intrinsics-disable"
argument_list|,
literal|"Disable non-FORTRAN-77 intrinsics f2c supports"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-ff2c-intrinsics-enable"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-ff2c-intrinsics-hide"
argument_list|,
literal|"Hide non-FORTRAN-77 intrinsics f2c supports"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-ff90-intrinsics-delete"
argument_list|,
literal|"Delete non-FORTRAN-77 intrinsics F90 supports"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-ff90-intrinsics-disable"
argument_list|,
literal|"Disable non-FORTRAN-77 intrinsics F90 supports"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-ff90-intrinsics-enable"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-ff90-intrinsics-hide"
argument_list|,
literal|"Hide non-FORTRAN-77 intrinsics F90 supports"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fgnu-intrinsics-delete"
argument_list|,
literal|"Delete non-FORTRAN-77 intrinsics g77 supports"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fgnu-intrinsics-disable"
argument_list|,
literal|"Disable non-FORTRAN 77 intrinsics F90 supports"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fgnu-intrinsics-enable"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fgnu-intrinsics-hide"
argument_list|,
literal|"Hide non-FORTRAN 77 intrinsics F90 supports"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fmil-intrinsics-delete"
argument_list|,
literal|"Delete MIL-STD 1753 intrinsics"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fmil-intrinsics-disable"
argument_list|,
literal|"Disable MIL-STD 1753 intrinsics"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fmil-intrinsics-enable"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fmil-intrinsics-hide"
argument_list|,
literal|"Hide MIL-STD 1753 intrinsics"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-funix-intrinsics-delete"
argument_list|,
literal|"Delete libU77 intrinsics"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-funix-intrinsics-disable"
argument_list|,
literal|"Disable libU77 intrinsics"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-funix-intrinsics-enable"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-funix-intrinsics-hide"
argument_list|,
literal|"Hide libU77 intrinsics"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fvxt-intrinsics-delete"
argument_list|,
literal|"Delete non-FORTRAN-77 intrinsics VXT FORTRAN supports"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fvxt-intrinsics-disable"
argument_list|,
literal|"Disable non-FORTRAN-77 intrinsics VXT FORTRAN supports"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fvxt-intrinsics-enable"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fvxt-intrinsics-hide"
argument_list|,
literal|"Hide non-FORTRAN-77 intrinsics VXT FORTRAN supports"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fzeros"
argument_list|,
literal|"Treat initial values of 0 like non-zero values"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-zeros"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fdebug-kludge"
argument_list|,
literal|"Emit special debugging information for COMMON and EQUIVALENCE"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-debug-kludge"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fonetrip"
argument_list|,
literal|"Take at least one trip through each iterative DO loop"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-onetrip"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fsilent"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-silent"
argument_list|,
literal|"Print names of program units as they are compiled"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fglobals"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-globals"
argument_list|,
literal|"Disable fatal diagnostics about inter-procedural problems"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-ftypeless-boz"
argument_list|,
literal|"Make prefix-radix non-decimal constants be typeless"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-typeless-boz"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fbounds-check"
argument_list|,
literal|"Generate code to check subscript and substring bounds"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-bounds-check"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-ffortran-bounds-check"
argument_list|,
literal|"Fortran-specific form of -fbounds-check"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-fno-fortran-bounds-check"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-Wglobals"
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-Wno-globals"
argument_list|,
literal|"Disable warnings about inter-procedural problems"
argument_list|)
end_macro

begin_comment
comment|/*"-Wimplicit",*/
end_comment

begin_comment
comment|/*"-Wno-implicit",*/
end_comment

begin_macro
name|FTNOPT
argument_list|(
literal|"-Wsurprising"
argument_list|,
literal|"Warn about constructs with surprising meanings"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-Wno-surprising"
argument_list|,
literal|""
argument_list|)
end_macro

begin_comment
comment|/*"-Wall",*/
end_comment

begin_comment
comment|/* Prefix options.  */
end_comment

begin_macro
name|FTNOPT
argument_list|(
literal|"-I"
argument_list|,
literal|"Add a directory for INCLUDE searching"
argument_list|)
end_macro

begin_macro
name|FTNOPT
argument_list|(
literal|"-ffixed-line-length-"
argument_list|,
literal|"Set the maximum line length"
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|FTNOPT
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

