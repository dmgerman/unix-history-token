begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for switches for C++.    Copyright (C) 1995, 96-97, 1998 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_macro
name|DEFINE_LANG_NAME
argument_list|(
literal|"C++"
argument_list|)
end_macro

begin_comment
comment|/* This is the contribution to the `lang_options' array in gcc.c for    g++.  */
end_comment

begin_block
block|{
literal|"-faccess-control"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-access-control"
operator|,
literal|"Do not obey access control semantics"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fall-virtual"
operator|,
literal|"Make all member functions virtual"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-all-virtual"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-falt-external-templates"
operator|,
literal|"Change when template instances are emitted"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-alt-external-templates"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fansi-overloading"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-ansi-overloading"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fcheck-new"
operator|,
literal|"Check the return value of new"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-check-new"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fconserve-space"
operator|,
literal|"Reduce size of object files"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-conserve-space"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fconst-strings"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-const-strings"
operator|,
literal|"Make string literals `char[]' instead of `const char[]'"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fdefault-inline"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-default-inline"
operator|,
literal|"Do not inline member functions by default"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-frtti"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-rtti"
operator|,
literal|"Do not generate run time type descriptor information"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-felide-constructors"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-elide-constructors"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fenum-int-equiv"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-enum-int-equiv"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fexternal-templates"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-external-templates"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ffor-scope"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-for-scope"
operator|,
literal|"Scope of for-init-statement vars extends outside"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fguiding-decls"
operator|,
literal|"Implement guiding declarations"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-guiding-decls"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fgnu-keywords"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-gnu-keywords"
operator|,
literal|"Do not recognise GNU defined keywords"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fhandle-exceptions"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-handle-exceptions"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fhandle-signatures"
operator|,
literal|"Handle signature language constructs"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-handle-signatures"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fhonor-std"
operator|,
literal|"Treat the namespace `std' as a normal namespace"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-honor-std"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fhuge-objects"
operator|,
literal|"Enable support for huge objects"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-huge-objects"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fimplement-inlines"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-implement-inlines"
operator|,
literal|"Export functions even if they can be inlined"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fimplicit-templates"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-implicit-templates"
operator|,
literal|"Only emit explicit template instatiations"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fimplicit-inline-templates"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-implicit-inline-templates"
operator|,
literal|"Only emit explicit instatiations of inline templates"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-finit-priority"
operator|,
literal|"Handle the init_priority attribute"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-init-priority"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-flabels-ok"
operator|,
literal|"Labels can be used as first class objects"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-labels-ok"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fmemoize-lookups"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-memoize-lookups"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fname-mangling-version-"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fnew-abi"
operator|,
literal|"Enable experimental ABI changes"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-new-abi"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fnonnull-objects"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-nonnull-objects"
operator|,
literal|"Do not assume that a reference is always valid"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-foperator-names"
operator|,
literal|"Recognise and/bitand/bitor/compl/not/or/xor"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-operator-names"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-foptional-diags"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-optional-diags"
operator|,
literal|"Disable optional diagnostics"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fpermissive"
operator|,
literal|"Downgrade conformance errors to warnings"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-permissive"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-frepo"
operator|,
literal|"Enable automatic template instantiation"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-repo"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fsave-memoized"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-save-memoized"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fsquangle"
operator|,
literal|"Enable squashed name mangling"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-squangle"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fstats"
operator|,
literal|"Display statistics accumulated during compilation"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-stats"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fstrict-prototype"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-strict-prototype"
operator|,
literal|"Do not assume that empty prototype means no args"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-ftemplate-depth-"
operator|,
literal|"Specify maximum template instantiation depth"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fthis-is-variable"
operator|,
literal|"Make 'this' not be type '* const'"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-this-is-variable"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fvtable-gc"
operator|,
literal|"Discard unused virtual functions"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-vtable-gc"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fvtable-thunks"
operator|,
literal|"Implement vtables using thunks"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-vtable-thunks"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fweak"
operator|,
literal|"Emit common-like symbols as weak symbols"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-weak"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fxref"
operator|,
literal|"Emit cross referencing information"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-xref"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wreturn-type"
operator|,
literal|"Warn about inconsistent return types"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wno-return-type"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Woverloaded-virtual"
operator|,
literal|"Warn about overloaded virtual function names"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wno-overloaded-virtual"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wctor-dtor-privacy"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wno-ctor-dtor-privacy"
operator|,
literal|"Don't warn when all ctors/dtors are private"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wnon-virtual-dtor"
operator|,
literal|"Warn about non virtual destructors"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wno-non-virtual-dtor"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wextern-inline"
operator|,
literal|"Warn when a function is declared extern, then inline"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wno-extern-inline"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wreorder"
operator|,
literal|"Warn when the compiler reorders code"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wno-reorder"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wsynth"
operator|,
literal|"Warn when synthesis behaviour differs from Cfront"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wno-synth"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wpmf-conversions"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wno-pmf-conversions"
operator|,
literal|"Don't warn when type converting pointers to member functions"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Weffc++"
operator|,
literal|"Warn about violations of Effective C++ style rules"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wno-effc++"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wsign-promo"
operator|,
literal|"Warn when overload promotes from unsigned to signed"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wno-sign-promo"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wold-style-cast"
operator|,
literal|"Warn if a C style cast is used in a program"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wno-old-style-cast"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wnon-template-friend"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wno-non-template-friend"
operator|,
literal|"Don't warn when non-templatized friend functions are declared within a template"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wdeprecated"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wno-deprecated"
operator|,
literal|"Don't announce deprecation of compiler features"
block|}
end_block

begin_operator
operator|,
end_operator

end_unit

