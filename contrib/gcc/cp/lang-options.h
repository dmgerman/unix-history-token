begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for switches for C++.    Copyright (C) 1995, 1996, 1997, 1998, 1999, 2000    Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_macro
name|DEFINE_LANG_NAME
argument_list|(
literal|"C++"
argument_list|)
end_macro

begin_comment
comment|/* This is the contribution to the `documented_lang_options' array in    toplev.c for g++.  */
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
name|N_
argument_list|(
literal|"Do not obey access control semantics"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-falt-external-templates"
operator|,
name|N_
argument_list|(
literal|"Change when template instances are emitted"
argument_list|)
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
name|N_
argument_list|(
literal|"Check the return value of new"
argument_list|)
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
name|N_
argument_list|(
literal|"Reduce size of object files"
argument_list|)
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
name|N_
argument_list|(
literal|"Make string literals `char[]' instead of `const char[]'"
argument_list|)
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
literal|"-fdump-translation-unit-"
operator|,
name|N_
argument_list|(
literal|"Dump the entire translation unit to a file"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-default-inline"
operator|,
name|N_
argument_list|(
literal|"Do not inline member functions by default"
argument_list|)
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
name|N_
argument_list|(
literal|"Do not generate run time type descriptor information"
argument_list|)
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
literal|"-fenforce-eh-specs"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-enforce-eh-specs"
operator|,
name|N_
argument_list|(
literal|"Do not generate code to check exception specifications"
argument_list|)
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
name|N_
argument_list|(
literal|"Scope of for-init-statement vars extends outside"
argument_list|)
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
name|N_
argument_list|(
literal|"Do not recognize GNU defined keywords"
argument_list|)
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
literal|"-fhuge-objects"
operator|,
name|N_
argument_list|(
literal|"Enable support for huge objects"
argument_list|)
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
name|N_
argument_list|(
literal|"Export functions even if they can be inlined"
argument_list|)
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
name|N_
argument_list|(
literal|"Only emit explicit template instatiations"
argument_list|)
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
name|N_
argument_list|(
literal|"Only emit explicit instatiations of inline templates"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-finit-priority"
operator|,
literal|""
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
literal|"-fms-extensions"
operator|,
name|N_
argument_list|(
literal|"Don't pedwarn about uses of Microsoft extensions"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-ms-extensions"
operator|,
literal|""
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-foperator-names"
operator|,
name|N_
argument_list|(
literal|"Recognize and/bitand/bitor/compl/not/or/xor"
argument_list|)
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
name|N_
argument_list|(
literal|"Disable optional diagnostics"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fpermissive"
operator|,
name|N_
argument_list|(
literal|"Downgrade conformance errors to warnings"
argument_list|)
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
name|N_
argument_list|(
literal|"Enable automatic template instantiation"
argument_list|)
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
literal|"-fstats"
operator|,
name|N_
argument_list|(
literal|"Display statistics accumulated during compilation"
argument_list|)
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
literal|"-ftemplate-depth-"
operator|,
name|N_
argument_list|(
literal|"Specify maximum template instantiation depth"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fuse-cxa-atexit"
operator|,
name|N_
argument_list|(
literal|"Use __cxa_atexit to register destructors"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-fno-use-cxa-atexit"
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
name|N_
argument_list|(
literal|"Discard unused virtual functions"
argument_list|)
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
name|N_
argument_list|(
literal|"Implement vtables using thunks"
argument_list|)
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
name|N_
argument_list|(
literal|"Emit common-like symbols as weak symbols"
argument_list|)
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
name|N_
argument_list|(
literal|"Emit cross referencing information"
argument_list|)
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
name|N_
argument_list|(
literal|"Warn about inconsistent return types"
argument_list|)
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
name|N_
argument_list|(
literal|"Warn about overloaded virtual function names"
argument_list|)
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
name|N_
argument_list|(
literal|"Don't warn when all ctors/dtors are private"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Wnon-virtual-dtor"
operator|,
name|N_
argument_list|(
literal|"Warn about non virtual destructors"
argument_list|)
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
name|N_
argument_list|(
literal|"Warn when a function is declared extern, then inline"
argument_list|)
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
name|N_
argument_list|(
literal|"Warn when the compiler reorders code"
argument_list|)
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
name|N_
argument_list|(
literal|"Warn when synthesis behavior differs from Cfront"
argument_list|)
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
name|N_
argument_list|(
literal|"Don't warn when type converting pointers to member functions"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"-Weffc++"
operator|,
name|N_
argument_list|(
literal|"Warn about violations of Effective C++ style rules"
argument_list|)
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
name|N_
argument_list|(
literal|"Warn when overload promotes from unsigned to signed"
argument_list|)
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
name|N_
argument_list|(
literal|"Warn if a C style cast is used in a program"
argument_list|)
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
name|N_
argument_list|(
literal|"Don't warn when non-templatized friend functions are declared within a template"
argument_list|)
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
name|N_
argument_list|(
literal|"Don't announce deprecation of compiler features"
argument_list|)
block|}
end_block

begin_operator
operator|,
end_operator

end_unit

