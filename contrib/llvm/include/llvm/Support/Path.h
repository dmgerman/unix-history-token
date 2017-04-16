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
name|enum
name|class
name|Style
block|{
name|windows
operator|,
name|posix
operator|,
name|native
block|}
empty_stmt|;
comment|/// @name Lexical Component Iterator
comment|/// @{
comment|/// @brief Path iterator.
comment|///
comment|/// This is an input iterator that iterates over the individual components in
comment|/// \a path. The traversal order is as follows:
comment|/// * The root-name element, if present.
comment|/// * The root-directory element, if present.
comment|/// * Each successive filename element, if present.
comment|/// * Dot, if one or more trailing non-root slash characters are present.
comment|/// Traversing backwards is possible with \a reverse_iterator
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
range|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|input_iterator_tag
decl_stmt|, const
name|StringRef
decl|>
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
name|Style
name|S
decl_stmt|;
comment|///< The path style to use.
comment|// An end iterator has Position = Path.size() + 1.
name|friend
name|const_iterator
name|begin
parameter_list|(
name|StringRef
name|path
parameter_list|,
name|Style
name|style
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
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|RHS
operator|)
return|;
block|}
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
comment|/// @brief Reverse path iterator.
comment|///
comment|/// This is an input iterator that iterates over the individual components in
comment|/// \a path in reverse order. The traversal order is exactly reversed from that
comment|/// of \a const_iterator
name|class
name|reverse_iterator
range|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|input_iterator_tag
decl_stmt|, const
name|StringRef
decl|>
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
name|Style
name|S
decl_stmt|;
comment|///< The path style to use.
name|friend
name|reverse_iterator
name|rbegin
parameter_list|(
name|StringRef
name|path
parameter_list|,
name|Style
name|style
parameter_list|)
function_decl|;
name|friend
name|reverse_iterator
name|rend
parameter_list|(
name|StringRef
name|path
parameter_list|)
function_decl|;
name|public
label|:
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
name|reverse_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
expr_stmt|;
comment|// preincrement
name|bool
name|operator
operator|==
operator|(
specifier|const
name|reverse_iterator
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
name|reverse_iterator
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|RHS
operator|)
return|;
block|}
comment|/// @brief Difference in bytes between this and RHS.
name|ptrdiff_t
name|operator
operator|-
operator|(
specifier|const
name|reverse_iterator
operator|&
name|RHS
operator|)
specifier|const
expr_stmt|;
block|}
empty_stmt|;
comment|/// @brief Get begin iterator over \a path.
comment|/// @param path Input path.
comment|/// @returns Iterator initialized with the first component of \a path.
name|const_iterator
name|begin
parameter_list|(
name|StringRef
name|path
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
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
name|reverse_iterator
name|rbegin
parameter_list|(
name|StringRef
name|path
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
parameter_list|)
function_decl|;
comment|/// @brief Get reverse end iterator over \a path.
comment|/// @param path Input path.
comment|/// @returns Iterator initialized to the reverse end of \a path.
name|reverse_iterator
name|rend
parameter_list|(
name|StringRef
name|path
parameter_list|)
function_decl|;
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
argument_list|,
name|Style
name|style
operator|=
name|Style
operator|::
name|native
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
argument_list|,
name|Style
name|style
operator|=
name|Style
operator|::
name|native
argument_list|)
decl_stmt|;
comment|/// @brief Replace matching path prefix with another path.
comment|///
comment|/// @code
comment|///   /foo, /old, /new => /foo
comment|///   /old/foo, /old, /new => /new/foo
comment|///   /foo,<empty>, /new => /new/foo
comment|///   /old/foo, /old,<empty> => /foo
comment|/// @endcode
comment|///
comment|/// @param Path If \a Path starts with \a OldPrefix modify to instead
comment|///        start with \a NewPrefix.
comment|/// @param OldPrefix The path prefix to strip from \a Path.
comment|/// @param NewPrefix The path prefix to replace \a NewPrefix with.
name|void
name|replace_path_prefix
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Path
argument_list|,
specifier|const
name|StringRef
operator|&
name|OldPrefix
argument_list|,
specifier|const
name|StringRef
operator|&
name|NewPrefix
argument_list|,
name|Style
name|style
operator|=
name|Style
operator|::
name|native
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
name|Style
name|style
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
argument_list|,
name|Style
name|style
operator|=
name|Style
operator|::
name|native
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
argument_list|,
name|Style
name|style
operator|=
name|Style
operator|::
name|native
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
argument_list|,
name|Style
name|style
operator|=
name|Style
operator|::
name|native
argument_list|)
decl_stmt|;
comment|/// @brief Replaces backslashes with slashes if Windows.
comment|///
comment|/// @param path processed path
comment|/// @result The result of replacing backslashes with forward slashes if Windows.
comment|/// On Unix, this function is a no-op because backslashes are valid path
comment|/// chracters.
name|std
operator|::
name|string
name|convert_to_slash
argument_list|(
argument|StringRef path
argument_list|,
argument|Style style = Style::native
argument_list|)
expr_stmt|;
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
name|StringRef
name|root_name
parameter_list|(
name|StringRef
name|path
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
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
name|StringRef
name|root_directory
parameter_list|(
name|StringRef
name|path
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
parameter_list|)
function_decl|;
comment|/// @brief Get root path.
comment|///
comment|/// Equivalent to root_name + root_directory.
comment|///
comment|/// @param path Input path.
comment|/// @result The root path of \a path if it has one, otherwise "".
name|StringRef
name|root_path
parameter_list|(
name|StringRef
name|path
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
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
name|StringRef
name|relative_path
parameter_list|(
name|StringRef
name|path
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
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
name|StringRef
name|parent_path
parameter_list|(
name|StringRef
name|path
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
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
name|StringRef
name|filename
parameter_list|(
name|StringRef
name|path
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
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
name|StringRef
name|stem
parameter_list|(
name|StringRef
name|path
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
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
name|StringRef
name|extension
parameter_list|(
name|StringRef
name|path
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
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
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
parameter_list|)
function_decl|;
comment|/// @brief Return the preferred separator for this platform.
comment|///
comment|/// @result StringRef of the preferred separator, null-terminated.
name|StringRef
name|get_separator
parameter_list|(
name|Style
name|style
init|=
name|Style
operator|::
name|native
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
comment|/// @brief Get the user's home directory.
comment|///
comment|/// @param result Holds the resulting path name.
comment|/// @result True if a home directory is set, false otherwise.
name|bool
name|home_directory
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|result
argument_list|)
decl_stmt|;
comment|/// @brief Get the user's cache directory.
comment|///
comment|/// Expect the resulting path to be a directory shared with other
comment|/// applications/services used by the user. Params \p Path1 to \p Path3 can be
comment|/// used to append additional directory names to the resulting path. Recommended
comment|/// pattern is<user_cache_directory>/<vendor>/<application>.
comment|///
comment|/// @param Result Holds the resulting path.
comment|/// @param Path1 Additional path to be appended to the user's cache directory
comment|/// path. "" can be used to append nothing.
comment|/// @param Path2 Second additional path to be appended.
comment|/// @param Path3 Third additional path to be appended.
comment|/// @result True if a cache directory path is set, false otherwise.
name|bool
name|user_cache_directory
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Result
argument_list|,
specifier|const
name|Twine
operator|&
name|Path1
argument_list|,
specifier|const
name|Twine
operator|&
name|Path2
operator|=
literal|""
argument_list|,
specifier|const
name|Twine
operator|&
name|Path3
operator|=
literal|""
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
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
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
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
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
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
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
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
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
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
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
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
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
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
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
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
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
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
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
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
parameter_list|)
function_decl|;
comment|/// @brief Remove redundant leading "./" pieces and consecutive separators.
comment|///
comment|/// @param path Input path.
comment|/// @result The cleaned-up \a path.
name|StringRef
name|remove_leading_dotslash
parameter_list|(
name|StringRef
name|path
parameter_list|,
name|Style
name|style
init|=
name|Style
operator|::
name|native
parameter_list|)
function_decl|;
comment|/// @brief In-place remove any './' and optionally '../' components from a path.
comment|///
comment|/// @param path processed path
comment|/// @param remove_dot_dot specify if '../' (except for leading "../") should be
comment|/// removed
comment|/// @result True if path was changed
name|bool
name|remove_dots
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|path
argument_list|,
name|bool
name|remove_dot_dot
operator|=
name|false
argument_list|,
name|Style
name|style
operator|=
name|Style
operator|::
name|native
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace path
end_comment

begin_comment
unit|}
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

