begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Shared between kernel& process */
end_comment

begin_comment
comment|/* $FreeBSD$ */
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
define|#
directive|define
name|BLOCK_RAW
value|0
comment|/* 2352 bytes, raw data */
define|#
directive|define
name|BLOCK_RAWPQ
value|1
comment|/* 2368 bytes, raw data with P and Q subchannels */
define|#
directive|define
name|BLOCK_RAWPW
value|2
comment|/* 2448 bytes, raw data with P-W subchannel appended */
define|#
directive|define
name|BLOCK_MODE_1
value|8
comment|/* 2048 bytes, mode 1 (ISO/IEC 10149) */
define|#
directive|define
name|BLOCK_MODE_2
value|9
comment|/* 2336 bytes, mode 2 (ISO/IEC 10149) */
define|#
directive|define
name|BLOCK_MODE_2_FORM_1
value|10
comment|/* 2048 bytes, CD-ROM XA form 1 */
define|#
directive|define
name|BLOCK_MODE_2_FORM_1b
value|11
comment|/* 2056 bytes, CD-ROM XA form 1 */
define|#
directive|define
name|BLOCK_MODE_2_FORM_2
value|12
comment|/* 2324 bytes, CD-ROM XA form 2 */
define|#
directive|define
name|BLOCK_MODE_2_FORM_2b
value|13
comment|/* 2332 bytes, CD-ROM XA form 2 */
name|int
name|track_type
decl_stmt|;
comment|/* defines the number of bytes in a block */
define|#
directive|define
name|COPY_INHIBIT
value|0
comment|/* no copy allowed */
define|#
directive|define
name|COPY_PERMITTED
value|1
comment|/* track can be copied */
define|#
directive|define
name|COPY_SCMS
value|2
comment|/* alternate copy */
name|int
name|copy_bits
decl_stmt|;
comment|/* define the possibilities for copying */
name|int
name|track_number
decl_stmt|;
name|char
name|ISRC_country
index|[
literal|2
index|]
decl_stmt|;
comment|/* country code (2 chars) */
name|char
name|ISRC_owner
index|[
literal|3
index|]
decl_stmt|;
comment|/* owner code (3 chars) */
name|int
name|ISRC_year
decl_stmt|;
comment|/* year of recording */
name|char
name|ISRC_serial
index|[
literal|5
index|]
decl_stmt|;
comment|/* serial number */
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

begin_comment
comment|/*   * Finalize track  */
end_comment

begin_define
define|#
directive|define
name|WORMIOCFINISHTRACK
value|_IO('W', 23)
end_define

begin_struct
struct|struct
name|wormio_session_info
block|{
name|u_short
name|lead_in
decl_stmt|;
name|u_short
name|lead_out
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WORMIOCREADSESSIONINFO
value|_IOR('W', 31, struct wormio_session_info)
end_define

begin_struct
struct|struct
name|wormio_write_session
block|{
name|int
name|toc_type
decl_stmt|;
name|int
name|onp
decl_stmt|;
name|int
name|lofp
decl_stmt|;
name|int
name|length
decl_stmt|;
name|char
name|catalog
index|[
literal|13
index|]
decl_stmt|;
name|u_char
modifier|*
name|track_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WORMIOCWRITESESSION
value|_IOW('W', 32, struct wormio_write_session)
end_define

begin_struct
struct|struct
name|wormio_first_writable_addr
block|{
name|int
name|track
decl_stmt|;
name|int
name|mode
decl_stmt|;
name|int
name|raw
decl_stmt|;
name|int
name|audio
decl_stmt|;
name|int
modifier|*
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WORMIOCFIRSTWRITABLEADDR
value|_IOWR('W', 33, struct wormio_first_writable_addr)
end_define

begin_define
define|#
directive|define
name|CDRIOCBLANK
value|_IO('c', 100)
end_define

begin_define
define|#
directive|define
name|CDRIOCNEXTWRITEABLEADDR
value|_IOR('c', 101, int)
end_define

begin_comment
comment|/* Errors/warnings */
end_comment

begin_define
define|#
directive|define
name|WORM_SEQUENCE_ERROR
value|1
end_define

begin_define
define|#
directive|define
name|WORM_DUMMY_BLOCKS_ADDED
value|2
end_define

begin_define
define|#
directive|define
name|WORM_CALIBRATION_AREA_ALMOST_FULL
value|3
end_define

begin_define
define|#
directive|define
name|WORM_CALIBRATION_AREA_FULL
value|4
end_define

begin_define
define|#
directive|define
name|WORM_BUFFER_UNDERRUN
value|5
end_define

begin_define
define|#
directive|define
name|WORM_ABSORPTION_CONTROL_ERROR
value|6
end_define

begin_define
define|#
directive|define
name|WORM_END_OF_MEDIUM
value|7
end_define

begin_define
define|#
directive|define
name|WORM_OPTIMUM_POWER_CALIBRATION_ERROR
value|8
end_define

begin_define
define|#
directive|define
name|WORMIOERROR
value|_IOR('W', 24, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_WORMIO_H_ */
end_comment

end_unit

