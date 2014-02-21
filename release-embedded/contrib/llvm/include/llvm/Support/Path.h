begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/Path.h - Path Operating System Concept ------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file declares the llvm::sys::path namespace. It is designed after
end_comment

begin_comment
comment|// TR2/boost filesystem (v3), but modified to remove exception handling and the
end_comment

begin_comment
comment|// path class.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_PATH_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_PATH_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
name|namespace
name|path
block|{
comment|/// @name Lexical Component Iterator
comment|/// @{
comment|/// @brief Path iterator.
comment|///
comment|/// This is a bidirectional iterator that iterates over the individual
comment|/// components in \a path. The forward traversal order is as follows:
comment|/// * The root-name element, if present.
comment|/// * The root-directory element, if present.
comment|/// * Each successive filename element, if present.
comment|/// * Dot, if one or more trailing non-root slash characters are present.
comment|/// The backwards traversal order is the reverse of forward traversal.
comment|///
comment|/// Iteration examples. Each component is separated by ',':
comment|/// @code
comment|///   /          => /
comment|///   /foo       => /,foo
comment|///   foo/       => foo,.
comment|///   /foo/bar   => /,foo,bar
comment|///   ../        => ..,.
comment|///   C:\foo\bar => C:,/,foo,bar
comment|/// @endcode
name|class
name|const_iterator
block|{
name|StringRef
name|Path
decl_stmt|;
comment|///< The entire path.
name|StringRef
name|Component
decl_stmt|;
comment|///< The current component. Not necessarily in Path.
name|size_t
name|Position
decl_stmt|;
comment|///< The iterators current position within Path.
comment|// An end iterator has Position = Path.size() + 1.
name|friend
name|const_iterator
name|begin
parameter_list|(
name|StringRef
name|path
parameter_list|)
function_decl|;
name|friend
name|const_iterator
name|end
parameter_list|(
name|StringRef
name|path
parameter_list|)
function_decl|;
name|public
label|:
typedef|typedef
specifier|const
name|StringRef
name|value_type
typedef|;
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
typedef|typedef
name|value_type
modifier|&
name|reference
typedef|;
typedef|typedef
name|value_type
modifier|*
name|pointer
typedef|;
typedef|typedef
name|std
operator|::
name|bidirectional_iterator_tag
name|iterator_category
expr_stmt|;
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Component
return|;
block|}
name|pointer
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
name|Component
return|;
block|}
name|const_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
expr_stmt|;
comment|// preincrement
name|const_iterator
operator|&
name|operator
operator|++
operator|(
name|int
operator|)
expr_stmt|;
comment|// postincrement
name|const_iterator
operator|&
name|operator
operator|--
operator|(
operator|)
expr_stmt|;
comment|// predecrement
name|const_iterator
operator|&
name|operator
operator|--
operator|(
name|int
operator|)
expr_stmt|;
comment|// postdecrement
name|bool
name|operator
operator|==
operator|(
specifier|const
name|const_iterator
operator|&
name|RHS
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|const_iterator
operator|&
name|RHS
operator|)
specifier|const
expr_stmt|;
comment|/// @brief Difference in bytes between this and RHS.
name|ptrdiff_t
name|operator
operator|-
operator|(
specifier|const
name|const_iterator
operator|&
name|RHS
operator|)
specifier|const
expr_stmt|;
block|}
empty_stmt|;
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|const_iterator
operator|>
name|reverse_iterator
expr_stmt|;
comment|/// @brief Get begin iterator over \a path.
comment|/// @param path Input path.
comment|/// @returns Iterator initialized with the first component of \a path.
name|const_iterator
name|begin
parameter_list|(
name|StringRef
name|path
parameter_list|)
function_decl|;
comment|/// @brief Get end iterator over \a path.
comment|/// @param path Input path.
comment|/// @returns Iterator initialized to the end of \a path.
name|const_iterator
name|end
parameter_list|(
name|StringRef
name|path
parameter_list|)
function_decl|;
comment|/// @brief Get reverse begin iterator over \a path.
comment|/// @param path Input path.
comment|/// @returns Iterator initialized with the first reverse component of \a path.
specifier|inline
name|reverse_iterator
name|rbegin
parameter_list|(
name|StringRef
name|path
parameter_list|)
block|{
return|return
name|reverse_iterator
argument_list|(
name|end
argument_list|(
name|path
argument_list|)
argument_list|)
return|;
block|}
comment|/// @brief Get reverse end iterator over \a path.
comment|/// @param path Input path.
comment|/// @returns Iterator initialized to the reverse end of \a path.
specifier|inline
name|reverse_iterator
name|rend
parameter_list|(
name|StringRef
name|path
parameter_list|)
block|{
return|return
name|reverse_iterator
argument_list|(
name|begin
argument_list|(
name|path
argument_list|)
argument_list|)
return|;
block|}
comment|/// @}
comment|/// @name Lexical Modifiers
comment|/// @{
comment|/// @brief Remove the last component from \a path unless it is the root dir.
comment|///
comment|/// @code
comment|///   directory/filename.cpp => directory/
comment|///   directory/             => directory
comment|///   filename.cpp           =><empty>
comment|///   /                      => /
comment|/// @endcode
comment|///
comment|/// @param path A path that is modified to not have a file component.
name|void
name|remove_filename
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|path
argument_list|)
decl_stmt|;
comment|/// @brief Replace the file extension of \a path with \a extension.
comment|///
comment|/// @code
comment|///   ./filename.cpp => ./filename.extension
comment|///   ./filename     => ./filename.extension
comment|///   ./             => ./.extension
comment|/// @endcode
comment|///
comment|/// @param path A path that has its extension replaced with \a extension.
comment|/// @param extension The extension to be added. It may be empty. It may also
comment|///                  optionally start with a '.', if it does not, one will be
comment|///                  prepended.
name|void
name|replace_extension
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|path
argument_list|,
specifier|const
name|Twine
operator|&
name|extension
argument_list|)
decl_stmt|;
comment|/// @brief Append to path.
comment|///
comment|/// @code
comment|///   /foo  + bar/f => /foo/bar/f
comment|///   /foo/ + bar/f => /foo/bar/f
comment|///   foo   + bar/f => foo/bar/f
comment|/// @endcode
comment|///
comment|/// @param path Set to \a path + \a component.
comment|/// @param a The component to be appended to \a path.
name|void
name|append
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|path
argument_list|,
specifier|const
name|Twine
operator|&
name|a
argument_list|,
specifier|const
name|Twine
operator|&
name|b
operator|=
literal|""
argument_list|,
specifier|const
name|Twine
operator|&
name|c
operator|=
literal|""
argument_list|,
specifier|const
name|Twine
operator|&
name|d
operator|=
literal|""
argument_list|)
decl_stmt|;
comment|/// @brief Append to path.
comment|///
comment|/// @code
comment|///   /foo  + [bar,f] => /foo/bar/f
comment|///   /foo/ + [bar,f] => /foo/bar/f
comment|///   foo   + [bar,f] => foo/bar/f
comment|/// @endcode
comment|///
comment|/// @param path Set to \a path + [\a begin, \a end).
comment|/// @param begin Start of components to append.
comment|/// @param end One past the end of components to append.
name|void
name|append
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|path
argument_list|,
name|const_iterator
name|begin
argument_list|,
name|const_iterator
name|end
argument_list|)
decl_stmt|;
comment|/// @}
comment|/// @name Transforms (or some other better name)
comment|/// @{
comment|/// Convert path to the native form. This is used to give paths to users and
comment|/// operating system calls in the platform's normal way. For example, on Windows
comment|/// all '/' are converted to '\'.
comment|///
comment|/// @param path A path that is transformed to native format.
comment|/// @param result Holds the result of the transformation.
name|void
name|native
argument_list|(
specifier|const
name|Twine
operator|&
name|path
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|result
argument_list|)
decl_stmt|;
comment|/// Convert path to the native form in place. This is used to give paths to
comment|/// users and operating system calls in the platform's normal way. For example,
comment|/// on Windows all '/' are converted to '\'.
comment|///
comment|/// @param path A path that is transformed to native format.
name|void
name|native
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|path
argument_list|)
decl_stmt|;
comment|/// @}
comment|/// @name Lexical Observers
comment|/// @{
comment|/// @brief Get root name.
comment|///
comment|/// @code
comment|///   //net/hello => //net
comment|///   c:/hello    => c: (on Windows, on other platforms nothing)
comment|///   /hello      =><empty>
comment|/// @endcode
comment|///
comment|/// @param path Input path.
comment|/// @result The root name of \a path if it has one, otherwise "".
specifier|const
name|StringRef
name|root_name
parameter_list|(
name|StringRef
name|path
parameter_list|)
function_decl|;
comment|/// @brief Get root directory.
comment|///
comment|/// @code
comment|///   /goo/hello => /
comment|///   c:/hello   => /
comment|///   d/file.txt =><empty>
comment|/// @endcode
comment|///
comment|/// @param path Input path.
comment|/// @result The root directory of \a path if it has one, otherwise
comment|///               "".
specifier|const
name|StringRef
name|root_directory
parameter_list|(
name|StringRef
name|path
parameter_list|)
function_decl|;
comment|/// @brief Get root path.
comment|///
comment|/// Equivalent to root_name + root_directory.
comment|///
comment|/// @param path Input path.
comment|/// @result The root path of \a path if it has one, otherwise "".
specifier|const
name|StringRef
name|root_path
parameter_list|(
name|StringRef
name|path
parameter_list|)
function_decl|;
comment|/// @brief Get relative path.
comment|///
comment|/// @code
comment|///   C:\hello\world => hello\world
comment|///   foo/bar        => foo/bar
comment|///   /foo/bar       => foo/bar
comment|/// @endcode
comment|///
comment|/// @param path Input path.
comment|/// @result The path starting after root_path if one exists, otherwise "".
specifier|const
name|StringRef
name|relative_path
parameter_list|(
name|StringRef
name|path
parameter_list|)
function_decl|;
comment|/// @brief Get parent path.
comment|///
comment|/// @code
comment|///   /          =><empty>
comment|///   /foo       => /
comment|///   foo/../bar => foo/..
comment|/// @endcode
comment|///
comment|/// @param path Input path.
comment|/// @result The parent path of \a path if one exists, otherwise "".
specifier|const
name|StringRef
name|parent_path
parameter_list|(
name|StringRef
name|path
parameter_list|)
function_decl|;
comment|/// @brief Get filename.
comment|///
comment|/// @code
comment|///   /foo.txt    => foo.txt
comment|///   .          => .
comment|///   ..         => ..
comment|///   /          => /
comment|/// @endcode
comment|///
comment|/// @param path Input path.
comment|/// @result The filename part of \a path. This is defined as the last component
comment|///         of \a path.
specifier|const
name|StringRef
name|filename
parameter_list|(
name|StringRef
name|path
parameter_list|)
function_decl|;
comment|/// @brief Get stem.
comment|///
comment|/// If filename contains a dot but not solely one or two dots, result is the
comment|/// substring of filename ending at (but not including) the last dot. Otherwise
comment|/// it is filename.
comment|///
comment|/// @code
comment|///   /foo/bar.txt => bar
comment|///   /foo/bar     => bar
comment|///   /foo/.txt    =><empty>
comment|///   /foo/.       => .
comment|///   /foo/..      => ..
comment|/// @endcode
comment|///
comment|/// @param path Input path.
comment|/// @result The stem of \a path.
specifier|const
name|StringRef
name|stem
parameter_list|(
name|StringRef
name|path
parameter_list|)
function_decl|;
comment|/// @brief Get extension.
comment|///
comment|/// If filename contains a dot but not solely one or two dots, result is the
comment|/// substring of filename starting at (and including) the last dot, and ending
comment|/// at the end of \a path. Otherwise "".
comment|///
comment|/// @code
comment|///   /foo/bar.txt => .txt
comment|///   /foo/bar     =><empty>
comment|///   /foo/.txt    => .txt
comment|/// @endcode
comment|///
comment|/// @param path Input path.
comment|/// @result The extension of \a path.
specifier|const
name|StringRef
name|extension
parameter_list|(
name|StringRef
name|path
parameter_list|)
function_decl|;
comment|/// @brief Check whether the given char is a path separator on the host OS.
comment|///
comment|/// @param value a character
comment|/// @result true if \a value is a path separator character on the host OS
name|bool
name|is_separator
parameter_list|(
name|char
name|value
parameter_list|)
function_decl|;
comment|/// @brief Get the typical temporary directory for the system, e.g.,
comment|/// "/var/tmp" or "C:/TEMP"
comment|///
comment|/// @param erasedOnReboot Whether to favor a path that is erased on reboot
comment|/// rather than one that potentially persists longer. This parameter will be
comment|/// ignored if the user or system has set the typical environment variable
comment|/// (e.g., TEMP on Windows, TMPDIR on *nix) to specify a temporary directory.
comment|///
comment|/// @param result Holds the resulting path name.
name|void
name|system_temp_directory
argument_list|(
name|bool
name|erasedOnReboot
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|result
argument_list|)
decl_stmt|;
comment|/// @brief Has root name?
comment|///
comment|/// root_name != ""
comment|///
comment|/// @param path Input path.
comment|/// @result True if the path has a root name, false otherwise.
name|bool
name|has_root_name
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|)
function_decl|;
comment|/// @brief Has root directory?
comment|///
comment|/// root_directory != ""
comment|///
comment|/// @param path Input path.
comment|/// @result True if the path has a root directory, false otherwise.
name|bool
name|has_root_directory
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|)
function_decl|;
comment|/// @brief Has root path?
comment|///
comment|/// root_path != ""
comment|///
comment|/// @param path Input path.
comment|/// @result True if the path has a root path, false otherwise.
name|bool
name|has_root_path
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|)
function_decl|;
comment|/// @brief Has relative path?
comment|///
comment|/// relative_path != ""
comment|///
comment|/// @param path Input path.
comment|/// @result True if the path has a relative path, false otherwise.
name|bool
name|has_relative_path
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|)
function_decl|;
comment|/// @brief Has parent path?
comment|///
comment|/// parent_path != ""
comment|///
comment|/// @param path Input path.
comment|/// @result True if the path has a parent path, false otherwise.
name|bool
name|has_parent_path
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|)
function_decl|;
comment|/// @brief Has filename?
comment|///
comment|/// filename != ""
comment|///
comment|/// @param path Input path.
comment|/// @result True if the path has a filename, false otherwise.
name|bool
name|has_filename
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|)
function_decl|;
comment|/// @brief Has stem?
comment|///
comment|/// stem != ""
comment|///
comment|/// @param path Input path.
comment|/// @result True if the path has a stem, false otherwise.
name|bool
name|has_stem
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|)
function_decl|;
comment|/// @brief Has extension?
comment|///
comment|/// extension != ""
comment|///
comment|/// @param path Input path.
comment|/// @result True if the path has a extension, false otherwise.
name|bool
name|has_extension
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|)
function_decl|;
comment|/// @brief Is path absolute?
comment|///
comment|/// @param path Input path.
comment|/// @result True if the path is absolute, false if it is not.
name|bool
name|is_absolute
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|)
function_decl|;
comment|/// @brief Is path relative?
comment|///
comment|/// @param path Input path.
comment|/// @result True if the path is relative, false if it is not.
name|bool
name|is_relative
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|)
function_decl|;
block|}
comment|// end namespace path
block|}
end_decl_stmt

begin_comment
comment|// end namespace sys
end_comment

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

