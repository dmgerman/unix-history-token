begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_CONFIG_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_CONFIG_H__
end_define

begin_define
define|#
directive|define
name|HAVE_FID
value|1
end_define

begin_comment
comment|/*  * Linux config variables, harcoded to values desirable for FreeBSD.  */
end_comment

begin_define
define|#
directive|define
name|CONFIG_SYSCTL
value|1
end_define

begin_define
define|#
directive|define
name|CONFIG_LBD
value|1
end_define

begin_define
define|#
directive|define
name|CONFIG_XFS_TRACE
value|0
end_define

begin_comment
comment|/*  * Tracing.  */
end_comment

begin_if
if|#
directive|if
name|CONFIG_XFS_TRACE
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|XFS_ALLOC_TRACE
value|1
end_define

begin_define
define|#
directive|define
name|XFS_ALLOC_TRACE
value|1
end_define

begin_define
define|#
directive|define
name|XFS_ATTR_TRACE
value|1
end_define

begin_define
define|#
directive|define
name|XFS_BLI_TRACE
value|1
end_define

begin_define
define|#
directive|define
name|XFS_BMAP_TRACE
value|1
end_define

begin_define
define|#
directive|define
name|XFS_BMBT_TRACE
value|1
end_define

begin_define
define|#
directive|define
name|XFS_DIR_TRACE
value|1
end_define

begin_define
define|#
directive|define
name|XFS_DIR2_TRACE
value|1
end_define

begin_define
define|#
directive|define
name|XFS_DQUOT_TRACE
value|1
end_define

begin_define
define|#
directive|define
name|XFS_ILOCK_TRACE
value|1
end_define

begin_define
define|#
directive|define
name|XFS_LOG_TRACE
value|1
end_define

begin_define
define|#
directive|define
name|XFS_RW_TRACE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XFS config defines.  */
end_comment

begin_define
define|#
directive|define
name|XFS_BIG_BLKNOS
value|1
end_define

begin_define
define|#
directive|define
name|XFS_BIG_INUMS
value|0
end_define

begin_undef
undef|#
directive|undef
name|XFS_STATS_OFF
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_CONFIG_H__ */
end_comment

end_unit

