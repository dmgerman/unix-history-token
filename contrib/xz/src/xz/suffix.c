begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       suffix.c
end_comment

begin_comment
comment|/// \brief      Checks filename suffix and creates the destination filename
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_include
include|#
directive|include
file|"private.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__DJGPP__
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// For case-insensitive filename suffix on case-insensitive systems
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TUKLIB_DOSLIKE
argument_list|)
operator|||
name|defined
argument_list|(
name|__VMS
argument_list|)
end_if

begin_define
define|#
directive|define
name|strcmp
value|strcasecmp
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|char
modifier|*
name|custom_suffix
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief      Test if the char is a directory separator
end_comment

begin_function
specifier|static
name|bool
name|is_dir_sep
parameter_list|(
name|char
name|c
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|TUKLIB_DOSLIKE
return|return
name|c
operator|==
literal|'/'
operator|||
name|c
operator|==
literal|'\\'
operator|||
name|c
operator|==
literal|':'
return|;
else|#
directive|else
return|return
name|c
operator|==
literal|'/'
return|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/// \brief      Test if the string contains a directory separator
end_comment

begin_function
specifier|static
name|bool
name|has_dir_sep
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|TUKLIB_DOSLIKE
return|return
name|strpbrk
argument_list|(
name|str
argument_list|,
literal|"/\\:"
argument_list|)
operator|!=
name|NULL
return|;
else|#
directive|else
return|return
name|strchr
argument_list|(
name|str
argument_list|,
literal|'/'
argument_list|)
operator|!=
name|NULL
return|;
endif|#
directive|endif
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__DJGPP__
end_ifdef

begin_comment
comment|/// \brief      Test for special suffix used for 8.3 short filenames (SFN)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return     If str matches *.?- or *.??-, true is returned. Otherwise
end_comment

begin_comment
comment|///             false is returned.
end_comment

begin_function
specifier|static
name|bool
name|has_sfn_suffix
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
if|if
condition|(
name|len
operator|>=
literal|4
operator|&&
name|str
index|[
name|len
operator|-
literal|1
index|]
operator|==
literal|'-'
operator|&&
name|str
index|[
name|len
operator|-
literal|2
index|]
operator|!=
literal|'.'
operator|&&
operator|!
name|is_dir_sep
argument_list|(
name|str
index|[
name|len
operator|-
literal|2
index|]
argument_list|)
condition|)
block|{
comment|// *.?-
if|if
condition|(
name|str
index|[
name|len
operator|-
literal|3
index|]
operator|==
literal|'.'
condition|)
return|return
operator|!
name|is_dir_sep
argument_list|(
name|str
index|[
name|len
operator|-
literal|4
index|]
argument_list|)
return|;
comment|// *.??-
if|if
condition|(
name|len
operator|>=
literal|5
operator|&&
operator|!
name|is_dir_sep
argument_list|(
name|str
index|[
name|len
operator|-
literal|3
index|]
argument_list|)
operator|&&
name|str
index|[
name|len
operator|-
literal|4
index|]
operator|==
literal|'.'
condition|)
return|return
operator|!
name|is_dir_sep
argument_list|(
name|str
index|[
name|len
operator|-
literal|5
index|]
argument_list|)
return|;
block|}
return|return
name|false
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \brief      Checks if src_name has given compressed_suffix
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param      suffix      Filename suffix to look for
end_comment

begin_comment
comment|/// \param      src_name    Input filename
end_comment

begin_comment
comment|/// \param      src_len     strlen(src_name)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return     If src_name has the suffix, src_len - strlen(suffix) is
end_comment

begin_comment
comment|///             returned. It's always a positive integer. Otherwise zero
end_comment

begin_comment
comment|///             is returned.
end_comment

begin_function
specifier|static
name|size_t
name|test_suffix
parameter_list|(
specifier|const
name|char
modifier|*
name|suffix
parameter_list|,
specifier|const
name|char
modifier|*
name|src_name
parameter_list|,
name|size_t
name|src_len
parameter_list|)
block|{
specifier|const
name|size_t
name|suffix_len
init|=
name|strlen
argument_list|(
name|suffix
argument_list|)
decl_stmt|;
comment|// The filename must have at least one character in addition to
comment|// the suffix. src_name may contain path to the filename, so we
comment|// need to check for directory separator too.
if|if
condition|(
name|src_len
operator|<=
name|suffix_len
operator|||
name|is_dir_sep
argument_list|(
name|src_name
index|[
name|src_len
operator|-
name|suffix_len
operator|-
literal|1
index|]
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|suffix
argument_list|,
name|src_name
operator|+
name|src_len
operator|-
name|suffix_len
argument_list|)
operator|==
literal|0
condition|)
return|return
name|src_len
operator|-
name|suffix_len
return|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/// \brief      Removes the filename suffix of the compressed file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return     Name of the uncompressed file, or NULL if file has unknown
end_comment

begin_comment
comment|///             suffix.
end_comment

begin_function
specifier|static
name|char
modifier|*
name|uncompressed_name
parameter_list|(
specifier|const
name|char
modifier|*
name|src_name
parameter_list|,
specifier|const
name|size_t
name|src_len
parameter_list|)
block|{
specifier|static
specifier|const
struct|struct
block|{
specifier|const
name|char
modifier|*
name|compressed
decl_stmt|;
specifier|const
name|char
modifier|*
name|uncompressed
decl_stmt|;
block|}
name|suffixes
index|[]
init|=
block|{
block|{
literal|".xz"
block|,
literal|""
block|}
block|,
block|{
literal|".txz"
block|,
literal|".tar"
block|}
block|,
comment|// .txz abbreviation for .txt.gz is rare.
block|{
literal|".lzma"
block|,
literal|""
block|}
block|,
ifdef|#
directive|ifdef
name|__DJGPP__
block|{
literal|".lzm"
block|,
literal|""
block|}
block|,
endif|#
directive|endif
block|{
literal|".tlz"
block|,
literal|".tar"
block|}
block|,
comment|// { ".gz",    "" },
comment|// { ".tgz",   ".tar" },
block|}
struct|;
specifier|const
name|char
modifier|*
name|new_suffix
init|=
literal|""
decl_stmt|;
name|size_t
name|new_len
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|opt_format
operator|==
name|FORMAT_RAW
condition|)
block|{
comment|// Don't check for known suffixes when --format=raw was used.
if|if
condition|(
name|custom_suffix
operator|==
name|NULL
condition|)
block|{
name|message_error
argument_list|(
name|_
argument_list|(
literal|"%s: With --format=raw, "
literal|"--suffix=.SUF is required unless "
literal|"writing to stdout"
argument_list|)
argument_list|,
name|src_name
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
block|}
else|else
block|{
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ARRAY_SIZE
argument_list|(
name|suffixes
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
name|new_len
operator|=
name|test_suffix
argument_list|(
name|suffixes
index|[
name|i
index|]
operator|.
name|compressed
argument_list|,
name|src_name
argument_list|,
name|src_len
argument_list|)
expr_stmt|;
if|if
condition|(
name|new_len
operator|!=
literal|0
condition|)
block|{
name|new_suffix
operator|=
name|suffixes
index|[
name|i
index|]
operator|.
name|uncompressed
expr_stmt|;
break|break;
block|}
block|}
ifdef|#
directive|ifdef
name|__DJGPP__
comment|// Support also *.?- -> *.? and *.??- -> *.?? on DOS.
comment|// This is done also when long filenames are available
comment|// to keep it easy to decompress files created when
comment|// long filename support wasn't available.
if|if
condition|(
name|new_len
operator|==
literal|0
operator|&&
name|has_sfn_suffix
argument_list|(
name|src_name
argument_list|,
name|src_len
argument_list|)
condition|)
block|{
name|new_suffix
operator|=
literal|""
expr_stmt|;
name|new_len
operator|=
name|src_len
operator|-
literal|1
expr_stmt|;
block|}
endif|#
directive|endif
block|}
if|if
condition|(
name|new_len
operator|==
literal|0
operator|&&
name|custom_suffix
operator|!=
name|NULL
condition|)
name|new_len
operator|=
name|test_suffix
argument_list|(
name|custom_suffix
argument_list|,
name|src_name
argument_list|,
name|src_len
argument_list|)
expr_stmt|;
if|if
condition|(
name|new_len
operator|==
literal|0
condition|)
block|{
name|message_warning
argument_list|(
name|_
argument_list|(
literal|"%s: Filename has an unknown suffix, "
literal|"skipping"
argument_list|)
argument_list|,
name|src_name
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
specifier|const
name|size_t
name|new_suffix_len
init|=
name|strlen
argument_list|(
name|new_suffix
argument_list|)
decl_stmt|;
name|char
modifier|*
name|dest_name
init|=
name|xmalloc
argument_list|(
name|new_len
operator|+
name|new_suffix_len
operator|+
literal|1
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
name|dest_name
argument_list|,
name|src_name
argument_list|,
name|new_len
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|dest_name
operator|+
name|new_len
argument_list|,
name|new_suffix
argument_list|,
name|new_suffix_len
argument_list|)
expr_stmt|;
name|dest_name
index|[
name|new_len
operator|+
name|new_suffix_len
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
name|dest_name
return|;
block|}
end_function

begin_comment
comment|/// This message is needed in multiple places in compressed_name(),
end_comment

begin_comment
comment|/// so the message has been put into its own function.
end_comment

begin_function
specifier|static
name|void
name|msg_suffix
parameter_list|(
specifier|const
name|char
modifier|*
name|src_name
parameter_list|,
specifier|const
name|char
modifier|*
name|suffix
parameter_list|)
block|{
name|message_warning
argument_list|(
name|_
argument_list|(
literal|"%s: File already has `%s' suffix, skipping"
argument_list|)
argument_list|,
name|src_name
argument_list|,
name|suffix
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/// \brief      Appends suffix to src_name
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In contrast to uncompressed_name(), we check only suffixes that are valid
end_comment

begin_comment
comment|/// for the specified file format.
end_comment

begin_function
specifier|static
name|char
modifier|*
name|compressed_name
parameter_list|(
specifier|const
name|char
modifier|*
name|src_name
parameter_list|,
name|size_t
name|src_len
parameter_list|)
block|{
comment|// The order of these must match the order in args.h.
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|all_suffixes
index|[]
index|[
literal|4
index|]
init|=
block|{
block|{
literal|".xz"
block|,
literal|".txz"
block|,
name|NULL
block|}
block|,
block|{
literal|".lzma"
block|,
ifdef|#
directive|ifdef
name|__DJGPP__
literal|".lzm"
block|,
endif|#
directive|endif
literal|".tlz"
block|,
name|NULL
comment|/* 		}, { 			".gz", 			".tgz", 			NULL */
block|}
block|,
block|{
comment|// --format=raw requires specifying the suffix
comment|// manually or using stdout.
name|NULL
block|}
block|}
decl_stmt|;
comment|// args.c ensures this.
name|assert
argument_list|(
name|opt_format
operator|!=
name|FORMAT_AUTO
argument_list|)
expr_stmt|;
specifier|const
name|size_t
name|format
init|=
name|opt_format
operator|-
literal|1
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|suffixes
init|=
name|all_suffixes
index|[
name|format
index|]
decl_stmt|;
comment|// Look for known filename suffixes and refuse to compress them.
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|suffixes
index|[
name|i
index|]
operator|!=
name|NULL
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|test_suffix
argument_list|(
name|suffixes
index|[
name|i
index|]
argument_list|,
name|src_name
argument_list|,
name|src_len
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|msg_suffix
argument_list|(
name|src_name
argument_list|,
name|suffixes
index|[
name|i
index|]
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
block|}
ifdef|#
directive|ifdef
name|__DJGPP__
comment|// Recognize also the special suffix that is used when long
comment|// filename (LFN) support isn't available. This suffix is
comment|// recognized on LFN systems too.
if|if
condition|(
name|opt_format
operator|==
name|FORMAT_XZ
operator|&&
name|has_sfn_suffix
argument_list|(
name|src_name
argument_list|,
name|src_len
argument_list|)
condition|)
block|{
name|msg_suffix
argument_list|(
name|src_name
argument_list|,
literal|"-"
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
endif|#
directive|endif
if|if
condition|(
name|custom_suffix
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|test_suffix
argument_list|(
name|custom_suffix
argument_list|,
name|src_name
argument_list|,
name|src_len
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|msg_suffix
argument_list|(
name|src_name
argument_list|,
name|custom_suffix
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
block|}
comment|// TODO: Hmm, maybe it would be better to validate this in args.c,
comment|// since the suffix handling when decoding is weird now.
if|if
condition|(
name|opt_format
operator|==
name|FORMAT_RAW
operator|&&
name|custom_suffix
operator|==
name|NULL
condition|)
block|{
name|message_error
argument_list|(
name|_
argument_list|(
literal|"%s: With --format=raw, "
literal|"--suffix=.SUF is required unless "
literal|"writing to stdout"
argument_list|)
argument_list|,
name|src_name
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
specifier|const
name|char
modifier|*
name|suffix
init|=
name|custom_suffix
operator|!=
name|NULL
condition|?
name|custom_suffix
else|:
name|suffixes
index|[
literal|0
index|]
decl_stmt|;
name|size_t
name|suffix_len
init|=
name|strlen
argument_list|(
name|suffix
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|__DJGPP__
if|if
condition|(
operator|!
name|_use_lfn
argument_list|(
name|src_name
argument_list|)
condition|)
block|{
comment|// Long filename (LFN) support isn't available and we are
comment|// limited to 8.3 short filenames (SFN).
comment|//
comment|// Look for suffix separator from the filename, and make sure
comment|// that it is in the filename, not in a directory name.
specifier|const
name|char
modifier|*
name|sufsep
init|=
name|strrchr
argument_list|(
name|src_name
argument_list|,
literal|'.'
argument_list|)
decl_stmt|;
if|if
condition|(
name|sufsep
operator|==
name|NULL
operator|||
name|sufsep
index|[
literal|1
index|]
operator|==
literal|'\0'
operator|||
name|has_dir_sep
argument_list|(
name|sufsep
argument_list|)
condition|)
block|{
comment|// src_name has no filename extension.
comment|//
comment|// Examples:
comment|// xz foo         -> foo.xz
comment|// xz -F lzma foo -> foo.lzm
comment|// xz -S x foo    -> foox
comment|// xz -S x foo.   -> foo.x
comment|// xz -S x.y foo  -> foox.y
comment|// xz -S .x foo   -> foo.x
comment|// xz -S .x foo.  -> foo.x
comment|//
comment|// Avoid double dots:
if|if
condition|(
name|sufsep
operator|!=
name|NULL
operator|&&
name|sufsep
index|[
literal|1
index|]
operator|==
literal|'\0'
operator|&&
name|suffix
index|[
literal|0
index|]
operator|==
literal|'.'
condition|)
operator|--
name|src_len
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|custom_suffix
operator|==
name|NULL
operator|&&
name|strcasecmp
argument_list|(
name|sufsep
argument_list|,
literal|".tar"
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|// ".tar" is handled specially.
comment|//
comment|// Examples:
comment|// xz foo.tar          -> foo.txz
comment|// xz -F lzma foo.tar  -> foo.tlz
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|tar_suffixes
index|[]
init|=
block|{
literal|".txz"
block|,
literal|".tlz"
block|,
comment|// ".tgz",
block|}
decl_stmt|;
name|suffix
operator|=
name|tar_suffixes
index|[
name|format
index|]
expr_stmt|;
name|suffix_len
operator|=
literal|4
expr_stmt|;
name|src_len
operator|-=
literal|4
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|custom_suffix
operator|==
name|NULL
operator|&&
name|opt_format
operator|==
name|FORMAT_XZ
condition|)
block|{
comment|// Instead of the .xz suffix, use a single
comment|// character at the end of the filename
comment|// extension. This is to minimize name
comment|// conflicts when compressing multiple files
comment|// with the same basename. E.g. foo.txt and
comment|// foo.exe become foo.tx- and foo.ex-. Dash
comment|// is rare as the last character of the
comment|// filename extension, so it seems to be
comment|// quite safe choice and it stands out better
comment|// in directory listings than e.g. x. For
comment|// comparison, gzip uses z.
name|suffix
operator|=
literal|"-"
expr_stmt|;
name|suffix_len
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|suffix
index|[
literal|0
index|]
operator|==
literal|'.'
condition|)
block|{
comment|// The first character of the suffix is a dot.
comment|// Throw away the original filename extension
comment|// and replace it with the new suffix.
comment|//
comment|// Examples:
comment|// xz -F lzma foo.txt  -> foo.lzm
comment|// xz -S .x  foo.txt   -> foo.x
name|src_len
operator|=
name|sufsep
operator|-
name|src_name
expr_stmt|;
block|}
else|else
block|{
comment|// The first character of the suffix is not
comment|// a dot. Preserve the first 0-2 characters
comment|// of the original filename extension.
comment|//
comment|// Examples:
comment|// xz foo.txt         -> foo.tx-
comment|// xz -S x  foo.c     -> foo.cx
comment|// xz -S ab foo.c     -> foo.cab
comment|// xz -S ab foo.txt   -> foo.tab
comment|// xz -S abc foo.txt  -> foo.abc
comment|//
comment|// Truncate the suffix to three chars:
if|if
condition|(
name|suffix_len
operator|>
literal|3
condition|)
name|suffix_len
operator|=
literal|3
expr_stmt|;
comment|// If needed, overwrite 1-3 characters.
if|if
condition|(
name|strlen
argument_list|(
name|sufsep
argument_list|)
operator|>
literal|4
operator|-
name|suffix_len
condition|)
name|src_len
operator|=
name|sufsep
operator|-
name|src_name
operator|+
literal|4
operator|-
name|suffix_len
expr_stmt|;
block|}
block|}
block|}
endif|#
directive|endif
name|char
modifier|*
name|dest_name
init|=
name|xmalloc
argument_list|(
name|src_len
operator|+
name|suffix_len
operator|+
literal|1
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
name|dest_name
argument_list|,
name|src_name
argument_list|,
name|src_len
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|dest_name
operator|+
name|src_len
argument_list|,
name|suffix
argument_list|,
name|suffix_len
argument_list|)
expr_stmt|;
name|dest_name
index|[
name|src_len
operator|+
name|suffix_len
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
name|dest_name
return|;
block|}
end_function

begin_function
specifier|extern
name|char
modifier|*
name|suffix_get_dest_name
parameter_list|(
specifier|const
name|char
modifier|*
name|src_name
parameter_list|)
block|{
name|assert
argument_list|(
name|src_name
operator|!=
name|NULL
argument_list|)
expr_stmt|;
comment|// Length of the name is needed in all cases to locate the end of
comment|// the string to compare the suffix, so calculate the length here.
specifier|const
name|size_t
name|src_len
init|=
name|strlen
argument_list|(
name|src_name
argument_list|)
decl_stmt|;
return|return
name|opt_mode
operator|==
name|MODE_COMPRESS
condition|?
name|compressed_name
argument_list|(
name|src_name
argument_list|,
name|src_len
argument_list|)
else|:
name|uncompressed_name
argument_list|(
name|src_name
argument_list|,
name|src_len
argument_list|)
return|;
block|}
end_function

begin_function
specifier|extern
name|void
name|suffix_set
parameter_list|(
specifier|const
name|char
modifier|*
name|suffix
parameter_list|)
block|{
comment|// Empty suffix and suffixes having a directory separator are
comment|// rejected. Such suffixes would break things later.
if|if
condition|(
name|suffix
index|[
literal|0
index|]
operator|==
literal|'\0'
operator|||
name|has_dir_sep
argument_list|(
name|suffix
argument_list|)
condition|)
name|message_fatal
argument_list|(
name|_
argument_list|(
literal|"%s: Invalid filename suffix"
argument_list|)
argument_list|,
name|suffix
argument_list|)
expr_stmt|;
comment|// Replace the old custom_suffix (if any) with the new suffix.
name|free
argument_list|(
name|custom_suffix
argument_list|)
expr_stmt|;
name|custom_suffix
operator|=
name|xstrdup
argument_list|(
name|suffix
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

end_unit

