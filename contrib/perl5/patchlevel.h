begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__PATCHLEVEL_H_INCLUDED__
end_ifndef

begin_comment
comment|/* do not adjust the whitespace! Configure expects the numbers to be  * exactly on the third column */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_define
define|#
directive|define
name|PERL_REVISION
value|5
end_define

begin_comment
comment|/* age */
end_comment

begin_define
define|#
directive|define
name|PERL_VERSION
value|6
end_define

begin_comment
comment|/* epoch */
end_comment

begin_define
define|#
directive|define
name|PERL_SUBVERSION
value|1
end_define

begin_comment
comment|/* generation */
end_comment

begin_comment
comment|/* The following numbers describe the earliest compatible version of    Perl ("compatibility" here being defined as sufficient binary/API    compatibility to run XS code built with the older version).    Normally this should not change across maintenance releases.     Note that this only refers to an out-of-the-box build.  Many non-default    options such as usemultiplicity tend to break binary compatibility    more often.     This is used by Configure et al to figure out     PERL_INC_VERSION_LIST, which lists version libraries    to include in @INC.  See INSTALL for how this works. */
end_comment

begin_define
define|#
directive|define
name|PERL_API_REVISION
value|5
end_define

begin_comment
comment|/* Adjust manually as needed.  */
end_comment

begin_define
define|#
directive|define
name|PERL_API_VERSION
value|5
end_define

begin_comment
comment|/* Adjust manually as needed.  */
end_comment

begin_define
define|#
directive|define
name|PERL_API_SUBVERSION
value|0
end_define

begin_comment
comment|/* Adjust manually as needed.  */
end_comment

begin_comment
comment|/*    XXX Note:  The selection of non-default Configure options, such    as -Duselonglong may invalidate these settings.  Currently, Configure    does not adequately test for this.   A.D.  Jan 13, 2000 */
end_comment

begin_define
define|#
directive|define
name|__PATCHLEVEL_H_INCLUDED__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 	local_patches -- list of locally applied less-than-subversion patches. 	If you're distributing such a patch, please give it a name and a 	one-line description, placed just before the last NULL in the array 	below.  If your patch fixes a bug in the perlbug database, please 	mention the bugid.  If your patch *IS* dependent on a prior patch, 	please place your applied patch line after its dependencies. This 	will help tracking of patch dependencies.  	Please edit the hunk of diff which adds your patch to this list, 	to remove context lines which would give patch problems.  For instance, 	if the original context diff is 	   *** patchlevel.h.orig<date here> 	   --- patchlevel.h<date here> 	   *** 38,43 *** 	   --- 38,44 --- 	     	,"FOO1235 - some patch" 	     	,"BAR3141 - another patch" 	     	,"BAZ2718 - and another patch" 	   + 	,"MINE001 - my new patch" 	     	,NULL 	     }; 	 	please change it to  	   *** patchlevel.h.orig<date here> 	   --- patchlevel.h<date here> 	   *** 41,43 *** 	   --- 41,44 --- 	   + 	,"MINE001 - my new patch" 	     }; 	 	(Note changes to line numbers as well as removal of context lines.) 	This will prevent patch from choking if someone has previously 	applied different patches than you.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PERL_PATCHLEVEL_H_IMPLICIT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LOCAL_PATCH_COUNT
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
modifier|*
name|local_patches
index|[]
init|=
block|{
name|NULL
block|,
literal|"SUIDMAIL - fixes for suidperl security"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initial space prevents this variable from being inserted in config.sh  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_PATCH_COUNT
define|\
value|(sizeof(local_patches)/sizeof(local_patches[0])-2)
end_define

begin_comment
comment|/* the old terms of reference, add them only when explicitly included */
end_comment

begin_define
define|#
directive|define
name|PATCHLEVEL
value|PERL_VERSION
end_define

begin_undef
undef|#
directive|undef
name|SUBVERSION
end_undef

begin_comment
comment|/* OS/390 has a SUBVERSION in a system header */
end_comment

begin_define
define|#
directive|define
name|SUBVERSION
value|PERL_SUBVERSION
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

