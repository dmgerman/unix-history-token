begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Shared between kernel& process */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_WORMIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_WORMIO_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/***************************************************************\ * Ioctls for the WORM drive					* \***************************************************************/
end_comment

begin_comment
comment|/*  * Quirk select: chose the set of quirk functions to use for this  * device.  */
end_comment

begin_struct
struct|struct
name|wormio_quirk_select
block|{
specifier|const
name|char
modifier|*
name|vendor
decl_stmt|;
comment|/* vendor name */
specifier|const
name|char
modifier|*
name|model
decl_stmt|;
comment|/* model name */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WORMIOCQUIRKSELECT
value|_IOW('W', 10, struct wormio_quirk_select)
end_define

begin_comment
comment|/*  * Prepare disk-wide parameters.  */
end_comment

begin_struct
struct|struct
name|wormio_prepare_disk
block|{
name|int
name|dummy
decl_stmt|;
comment|/* use dummy writes, laser turned off */
name|int
name|speed
decl_stmt|;
comment|/* drive speed selection */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WORMIOCPREPDISK
value|_IOW('W', 20, struct wormio_prepare_disk)
end_define

begin_comment
comment|/*  * Prepare track-specific parameters.  */
end_comment

begin_struct
struct|struct
name|wormio_prepare_track
block|{
name|int
name|audio
decl_stmt|;
comment|/* audio track (data track if 0) */
name|int
name|preemp
decl_stmt|;
comment|/* audio with preemphasis */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WORMIOCPREPTRACK
value|_IOW('W', 21, struct wormio_prepare_track)
end_define

begin_comment
comment|/*  * Fixation: write leadins and leadouts.  Select table-of-contents  * type for this session.  If onp is != 0, another session will be  * opened.  */
end_comment

begin_struct
struct|struct
name|wormio_fixation
block|{
name|int
name|toc_type
decl_stmt|;
comment|/* TOC type */
name|int
name|onp
decl_stmt|;
comment|/* open next program area */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WORMIOCFIXATION
value|_IOW('W', 22, struct wormio_fixation)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_WORMIO_H_ */
end_comment

end_unit

