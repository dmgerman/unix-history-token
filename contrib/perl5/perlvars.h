begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************/
end_comment

begin_comment
comment|/* Truly global */
end_comment

begin_comment
comment|/****************/
end_comment

begin_comment
comment|/* Don't forget to re-run embed.pl to propagate changes! */
end_comment

begin_comment
comment|/* This file describes the "global" variables used by perl  * This used to be in perl.h directly but we want to abstract out into  * distinct files which are per-thread, per-interpreter or really global,  * and how they're initialized.  *  * The 'G' prefix is only needed for vars that need appropriate #defines  * generated in embed*.h.  Such symbols are also used to generate  * the appropriate export list for win32. */
end_comment

begin_comment
comment|/* global state */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gcurinterp
argument_list|,
argument|PerlInterpreter *
argument_list|)
end_macro

begin_comment
comment|/* currently running interpreter 					 * (initial parent interpreter under 					 * useithreads) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_THREADS
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_ITHREADS
argument_list|)
end_if

begin_macro
name|PERLVAR
argument_list|(
argument|Gthr_key
argument_list|,
argument|perl_key
argument_list|)
end_macro

begin_comment
comment|/* key to retrieve per-thread struct */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* constants (these are not literals to facilitate pointer comparisons) */
end_comment

begin_macro
name|PERLVARIC
argument_list|(
argument|GYes
argument_list|,
argument|char *
argument_list|,
literal|"1"
argument_list|)
end_macro

begin_macro
name|PERLVARIC
argument_list|(
argument|GNo
argument_list|,
argument|char *
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|PERLVARIC
argument_list|(
argument|Ghexdigit
argument_list|,
argument|char *
argument_list|,
literal|"0123456789abcdef0123456789ABCDEF"
argument_list|)
end_macro

begin_macro
name|PERLVARIC
argument_list|(
argument|Gpatleave
argument_list|,
argument|char *
argument_list|,
literal|"\\.^$@dDwWsSbB+*?|()-nrtfeaxc0123456789[{]}"
argument_list|)
end_macro

begin_comment
comment|/* XXX does anyone even use this? */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Gdo_undump
argument_list|,
argument|bool
argument_list|,
argument|FALSE
argument_list|)
end_macro

begin_comment
comment|/* -u or dump seen? */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MYMALLOC
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|USE_THREADS
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_ITHREADS
argument_list|)
operator|)
end_if

begin_macro
name|PERLVAR
argument_list|(
argument|Gmalloc_mutex
argument_list|,
argument|perl_mutex
argument_list|)
end_macro

begin_comment
comment|/* Mutex for malloc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_ITHREADS
argument_list|)
end_if

begin_macro
name|PERLVAR
argument_list|(
argument|Gop_mutex
argument_list|,
argument|perl_mutex
argument_list|)
end_macro

begin_comment
comment|/* Mutex for op refcounting */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

