begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Character traits template for the -*- C++ -*- string classes.
end_comment

begin_comment
comment|// Copyright (C) 1994 Free Software Foundation
end_comment

begin_comment
comment|// This file is part of the GNU ANSI C++ Library.  This library is free
end_comment

begin_comment
comment|// software; you can redistribute it and/or modify it under the
end_comment

begin_comment
comment|// terms of the GNU General Public License as published by the
end_comment

begin_comment
comment|// Free Software Foundation; either version 2, or (at your option)
end_comment

begin_comment
comment|// any later version.
end_comment

begin_comment
comment|// This library is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|// but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
end_comment

begin_comment
comment|// GNU General Public License for more details.
end_comment

begin_comment
comment|// You should have received a copy of the GNU General Public License
end_comment

begin_comment
comment|// along with this library; see the file COPYING.  If not, write to the Free
end_comment

begin_comment
comment|// Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
end_comment

begin_comment
comment|// As a special exception, if you link this library with files
end_comment

begin_comment
comment|// compiled with a GNU compiler to produce an executable, this does not cause
end_comment

begin_comment
comment|// the resulting executable to be covered by the GNU General Public License.
end_comment

begin_comment
comment|// This exception does not however invalidate any other reasons why
end_comment

begin_comment
comment|// the executable file might be covered by the GNU General Public License.
end_comment

begin_comment
comment|// Written by Jason Merrill based upon the specification by Takanori Adachi
end_comment

begin_comment
comment|// in ANSI X3J16/94-0013R2.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STRING_CHAR_TRAITS__
end_ifndef

begin_define
define|#
directive|define
name|__STRING_CHAR_TRAITS__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_comment
comment|// For string_char_traits<char>
end_comment

begin_pragma
pragma|#
directive|pragma
name|interface
literal|"std/straits.h"
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_extern
extern|extern
literal|"C++"
block|{
name|template
operator|<
name|class
name|charT
operator|>
expr|struct
name|string_char_traits
block|{
typedef|typedef
name|charT
name|char_type
typedef|;
comment|// for users to acquire the basic character type
comment|// constraints
specifier|static
name|void
name|assign
argument_list|(
argument|char_type& c1
argument_list|,
argument|const char_type& c2
argument_list|)
block|{
name|c1
operator|=
name|c2
block|; }
specifier|static
name|bool
name|eq
argument_list|(
argument|const char_type& c1
argument_list|,
argument|const char_type& c2
argument_list|)
block|{
return|return
operator|(
name|c1
operator|==
name|c2
operator|)
return|;
block|}
specifier|static
name|bool
name|ne
parameter_list|(
specifier|const
name|char_type
modifier|&
name|c1
parameter_list|,
specifier|const
name|char_type
modifier|&
name|c2
parameter_list|)
block|{
return|return
operator|!
operator|(
name|c1
operator|==
name|c2
operator|)
return|;
block|}
specifier|static
name|bool
name|lt
parameter_list|(
specifier|const
name|char_type
modifier|&
name|c1
parameter_list|,
specifier|const
name|char_type
modifier|&
name|c2
parameter_list|)
block|{
return|return
operator|(
name|c1
operator|<
name|c2
operator|)
return|;
block|}
specifier|static
name|char_type
name|eos
parameter_list|()
block|{
return|return
name|char_type
argument_list|()
return|;
block|}
comment|// the null character
specifier|static
name|bool
name|is_del
parameter_list|(
name|char_type
name|a
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
comment|// characteristic function for delimiters of charT
comment|// speed-up functions
specifier|static
name|int
name|compare
parameter_list|(
specifier|const
name|char_type
modifier|*
name|s1
parameter_list|,
specifier|const
name|char_type
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
name|size_t
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|ne
argument_list|(
name|s1
index|[
name|i
index|]
argument_list|,
name|s2
index|[
name|i
index|]
argument_list|)
condition|)
return|return
name|lt
argument_list|(
name|s1
index|[
name|i
index|]
argument_list|,
name|s2
index|[
name|i
index|]
argument_list|)
condition|?
operator|-
literal|1
else|:
literal|1
return|;
return|return
literal|0
return|;
block|}
specifier|static
name|size_t
name|length
parameter_list|(
specifier|const
name|char_type
modifier|*
name|s
parameter_list|)
block|{
name|size_t
name|l
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|ne
argument_list|(
operator|*
name|s
operator|++
argument_list|,
name|eos
argument_list|()
argument_list|)
condition|)
operator|++
name|l
expr_stmt|;
return|return
name|l
return|;
block|}
specifier|static
name|char_type
modifier|*
name|copy
parameter_list|(
name|char_type
modifier|*
name|s1
parameter_list|,
specifier|const
name|char_type
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
for|for
control|(
init|;
name|n
operator|--
condition|;
control|)
name|assign
argument_list|(
name|s1
index|[
name|n
index|]
argument_list|,
name|s2
index|[
name|n
index|]
argument_list|)
expr_stmt|;
return|return
name|s1
return|;
block|}
specifier|static
name|char_type
modifier|*
name|move
parameter_list|(
name|char_type
modifier|*
name|s1
parameter_list|,
specifier|const
name|char_type
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
name|char_type
name|a
index|[
name|n
index|]
decl_stmt|;
name|size_t
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
operator|++
name|i
control|)
name|assign
argument_list|(
name|a
index|[
name|i
index|]
argument_list|,
name|s2
index|[
name|i
index|]
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
operator|++
name|i
control|)
name|assign
argument_list|(
name|s1
index|[
name|i
index|]
argument_list|,
name|a
index|[
name|i
index|]
argument_list|)
expr_stmt|;
return|return
name|s1
return|;
block|}
specifier|static
name|char_type
modifier|*
name|set
parameter_list|(
name|char_type
modifier|*
name|s1
parameter_list|,
specifier|const
name|char_type
modifier|&
name|c
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
for|for
control|(
init|;
name|n
operator|--
condition|;
control|)
name|assign
argument_list|(
name|s1
index|[
name|n
index|]
argument_list|,
name|c
argument_list|)
expr_stmt|;
return|return
name|s1
return|;
block|}
block|}
end_extern

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|istream
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|ostream
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<cctype>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_expr_stmt
unit|struct
name|string_char_traits
operator|<
name|char
operator|>
block|{
typedef|typedef
name|char
name|char_type
typedef|;
specifier|static
name|void
name|assign
argument_list|(
argument|char_type& c1
argument_list|,
argument|const char_type& c2
argument_list|)
block|{
name|c1
operator|=
name|c2
block|; }
specifier|static
name|bool
name|eq
argument_list|(
argument|const char_type& c1
argument_list|,
argument|const char_type& c2
argument_list|)
block|{
return|return
operator|(
name|c1
operator|==
name|c2
operator|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|bool
name|ne
parameter_list|(
specifier|const
name|char_type
modifier|&
name|c1
parameter_list|,
specifier|const
name|char_type
modifier|&
name|c2
parameter_list|)
block|{
return|return
operator|(
name|c1
operator|!=
name|c2
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|lt
parameter_list|(
specifier|const
name|char_type
modifier|&
name|c1
parameter_list|,
specifier|const
name|char_type
modifier|&
name|c2
parameter_list|)
block|{
return|return
operator|(
name|c1
operator|<
name|c2
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|char_type
name|eos
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|is_del
parameter_list|(
name|char_type
name|a
parameter_list|)
block|{
return|return
name|isspace
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|compare
parameter_list|(
specifier|const
name|char_type
modifier|*
name|s1
parameter_list|,
specifier|const
name|char_type
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
return|return
name|memcmp
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|size_t
name|length
parameter_list|(
specifier|const
name|char_type
modifier|*
name|s
parameter_list|)
block|{
return|return
name|strlen
argument_list|(
name|s
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|char_type
modifier|*
name|copy
parameter_list|(
name|char_type
modifier|*
name|s1
parameter_list|,
specifier|const
name|char_type
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
return|return
operator|(
name|char_type
operator|*
operator|)
name|memcpy
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|char_type
modifier|*
name|move
parameter_list|(
name|char_type
modifier|*
name|s1
parameter_list|,
specifier|const
name|char_type
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
return|return
operator|(
name|char_type
operator|*
operator|)
name|memmove
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|char_type
modifier|*
name|set
parameter_list|(
name|char_type
modifier|*
name|s1
parameter_list|,
specifier|const
name|char_type
modifier|&
name|c
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
return|return
operator|(
name|char_type
operator|*
operator|)
name|memset
argument_list|(
name|s1
argument_list|,
name|c
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_if
unit|};
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|<cwctype>
end_include

begin_endif
unit|struct string_char_traits<wchar_t> {   typedef wchar_t char_type;    static void assign (char_type& c1, const char_type& c2)     { c1 = c2; }   static bool eq (const char_type& c1, const char_type& c2)     { return (c1 == c2); }   static bool ne (const char_type& c1, const char_type& c2)     { return (c1 != c2); }   static bool lt (const char_type& c1, const char_type& c2)     { return (c1< c2); }   static char_type eos () { return 0; }   static bool is_del(char_type a) { return iswspace(a); }    static int compare (const char_type* s1, const char_type* s2, size_t n)     { return wmemcmp (s1, s2, n); }   static size_t length (const char_type* s)     { return wcslen (s); }   static char_type* copy (char_type* s1, const char_type* s2, size_t n)     { return wmemcpy (s1, s2, n); }   static char_type* set (char_type* s1, const char_type& c, size_t n)     { return wmemset (s1, c, n); } };
endif|#
directive|endif
end_endif

begin_comment
unit|}
comment|// extern "C++"
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

