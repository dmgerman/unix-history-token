begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * 386BSD:  * format a floppy disk  *  * First, totally uncomfortable and unreliable version.  * USE AT YOUR OWN RISK. NEITHER KIND OF WARRANTY OR LIABILITY.  * No complaints about "lost data", "destroyed diskette", "blown  * controllers" or so are accepted.  *  * Detailed bug reports, bug fixes, and suggestions are welcome.  * Author& Copyright:  *  (c) 1992, 1993 Joerg Wunsch, Dresden  *  joerg_wunsch@uriah.sax.de  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IOCTL_FD_H
end_ifndef

begin_define
define|#
directive|define
name|_IOCTL_FD_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_define
define|#
directive|define
name|FD_FORMAT_VERSION
value|110
end_define

begin_comment
comment|/* used to validate before formatting */
end_comment

begin_define
define|#
directive|define
name|FD_MAX_NSEC
value|36
end_define

begin_comment
comment|/* highest known number of spt - allow for */
end_comment

begin_comment
comment|/* 2.88 MB drives */
end_comment

begin_struct
struct|struct
name|fd_formb
block|{
name|int
name|format_version
decl_stmt|;
comment|/* == FD_FORMAT_VERSION */
name|int
name|cyl
decl_stmt|,
name|head
decl_stmt|;
name|int
name|transfer_rate
decl_stmt|;
comment|/* fdreg.h: FDC_???KBPS */
union|union
block|{
struct|struct
name|fd_form_data
block|{
comment|/* 			 * DO NOT CHANGE THE LAYOUT OF THIS STRUCTS 			 * it is hardware-dependant since it exactly 			 * matches the byte sequence to write to FDC 			 * during its `format track' operation 			 */
name|u_char
name|secshift
decl_stmt|;
comment|/* 0 -> 128, ...; usually 2 -> 512 */
name|u_char
name|nsecs
decl_stmt|;
comment|/* must be<= FD_MAX_NSEC */
name|u_char
name|gaplen
decl_stmt|;
comment|/* GAP 3 length; usually 84 */
name|u_char
name|fillbyte
decl_stmt|;
comment|/* usually 0xf6 */
struct|struct
name|fd_idfield_data
block|{
comment|/* 				 * data to write into id fields; 				 * for obscure formats, they mustn't match 				 * the real values (but mostly do) 				 */
name|u_char
name|cylno
decl_stmt|;
comment|/* 0 thru 79 (or 39) */
name|u_char
name|headno
decl_stmt|;
comment|/* 0, or 1 */
name|u_char
name|secno
decl_stmt|;
comment|/* starting at 1! */
name|u_char
name|secsize
decl_stmt|;
comment|/* usually 2 */
block|}
name|idfields
index|[
name|FD_MAX_NSEC
index|]
struct|;
comment|/* 0<= idx< nsecs used */
block|}
name|structured
struct|;
name|u_char
name|raw
index|[
literal|1
index|]
decl_stmt|;
comment|/* to have continuous indexed access */
block|}
name|format_info
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* make life easier */
end_comment

begin_define
define|#
directive|define
name|fd_formb_secshift
value|format_info.structured.secshift
end_define

begin_define
define|#
directive|define
name|fd_formb_nsecs
value|format_info.structured.nsecs
end_define

begin_define
define|#
directive|define
name|fd_formb_gaplen
value|format_info.structured.gaplen
end_define

begin_define
define|#
directive|define
name|fd_formb_fillbyte
value|format_info.structured.fillbyte
end_define

begin_comment
comment|/* these data must be filled in for(i = 0; i< fd_formb_nsecs; i++) */
end_comment

begin_define
define|#
directive|define
name|fd_formb_cylno
parameter_list|(
name|i
parameter_list|)
value|format_info.structured.idfields[i].cylno
end_define

begin_define
define|#
directive|define
name|fd_formb_headno
parameter_list|(
name|i
parameter_list|)
value|format_info.structured.idfields[i].headno
end_define

begin_define
define|#
directive|define
name|fd_formb_secno
parameter_list|(
name|i
parameter_list|)
value|format_info.structured.idfields[i].secno
end_define

begin_define
define|#
directive|define
name|fd_formb_secsize
parameter_list|(
name|i
parameter_list|)
value|format_info.structured.idfields[i].secsize
end_define

begin_struct
struct|struct
name|fd_type
block|{
name|int
name|sectrac
decl_stmt|;
comment|/* sectors per track         */
name|int
name|secsize
decl_stmt|;
comment|/* size code for sectors     */
name|int
name|datalen
decl_stmt|;
comment|/* data len when secsize = 0 */
name|int
name|gap
decl_stmt|;
comment|/* gap len between sectors   */
name|int
name|tracks
decl_stmt|;
comment|/* total num of tracks       */
name|int
name|size
decl_stmt|;
comment|/* size of disk in sectors   */
name|int
name|steptrac
decl_stmt|;
comment|/* steps per cylinder        */
name|int
name|trans
decl_stmt|;
comment|/* transfer speed code       */
name|int
name|heads
decl_stmt|;
comment|/* number of heads	     */
name|int
name|intleave
decl_stmt|;
comment|/* interleave factor         */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FD_FORM
value|_IOW('F', 61, struct fd_formb)
end_define

begin_comment
comment|/* format a track */
end_comment

begin_define
define|#
directive|define
name|FD_GTYPE
value|_IOR('F', 62, struct fd_type)
end_define

begin_comment
comment|/* get drive type */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !def _IOCTL_FD_H */
end_comment

end_unit

