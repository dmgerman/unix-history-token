begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__PATCHLEVEL_H_INCLUDED__
end_ifndef

begin_define
define|#
directive|define
name|PATCHLEVEL
value|5
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
value|3
end_define

begin_comment
comment|/* 	local_patches -- list of locally applied less-than-subversion patches. 	If you're distributing such a patch, please give it a name and a 	one-line description, placed just before the last NULL in the array 	below.  If your patch fixes a bug in the perlbug database, please 	mention the bugid.  If your patch *IS* dependent on a prior patch, 	please place your applied patch line after its dependencies. This 	will help tracking of patch dependencies.  	Please edit the hunk of diff which adds your patch to this list, 	to remove context lines which would give patch problems.  For instance, 	if the original context diff is 	   *** patchlevel.h.orig<date here> 	   --- patchlevel.h<date here> 	   *** 38,43 *** 	   --- 38,44 --- 	     	,"FOO1235 - some patch" 	     	,"BAR3141 - another patch" 	     	,"BAZ2718 - and another patch" 	   + 	,"MINE001 - my new patch" 	     	,NULL 	     }; 	 	please change it to  	   *** patchlevel.h.orig<date here> 	   --- patchlevel.h<date here> 	   *** 41,43 *** 	   --- 41,44 --- 	   + 	,"MINE001 - my new patch" 	     }; 	 	(Note changes to line numbers as well as removal of context lines.) 	This will prevent patch from choking if someone has previously 	applied different patches than you.  */
end_comment

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

begin_define
define|#
directive|define
name|__PATCHLEVEL_H_INCLUDED__
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

