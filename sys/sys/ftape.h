begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright (c) 1993 Steve Gerakines  *  *  This is freely redistributable software.  You may do anything you  *  wish with it, so long as the above notice stays intact.  *  *  THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS  *  OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  *  DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT,  *  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  *  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  *  IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  *  ftape.h - QIC-40/80 floppy tape driver functions  *  10/30/93 v0.3  *  Set up constant values.  Added support to get hardware info.  *  *  08/07/93 v0.2  *  Header file that sits in /sys/sys, first revision.  Support for  *  ioctl functions added.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_FTAPE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FTAPE_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/* Miscellaneous constant values */
end_comment

begin_define
define|#
directive|define
name|QCV_BLKSIZE
value|1024
end_define

begin_comment
comment|/* Size of a block */
end_comment

begin_define
define|#
directive|define
name|QCV_SEGSIZE
value|32768
end_define

begin_comment
comment|/* Size of a segment */
end_comment

begin_define
define|#
directive|define
name|QCV_BLKSEG
value|32
end_define

begin_comment
comment|/* Blocks per segment */
end_comment

begin_define
define|#
directive|define
name|QCV_ECCSIZE
value|3072
end_define

begin_comment
comment|/* Bytes ecc eats */
end_comment

begin_define
define|#
directive|define
name|QCV_ECCBLKS
value|3
end_define

begin_comment
comment|/* Blocks ecc eats */
end_comment

begin_define
define|#
directive|define
name|QCV_NFMT
value|3
end_define

begin_comment
comment|/* Number of tape formats */
end_comment

begin_define
define|#
directive|define
name|QCV_NLEN
value|5
end_define

begin_comment
comment|/* Number of tape lengths */
end_comment

begin_define
define|#
directive|define
name|QCV_HDRMAGIC
value|0xaa55aa55
end_define

begin_comment
comment|/* Magic for header segment */
end_comment

begin_define
define|#
directive|define
name|QCV_FSMAGIC
value|0x33cc33cc
end_define

begin_comment
comment|/* Magic for fileset */
end_comment

begin_define
define|#
directive|define
name|UCHAR
value|unsigned char
end_define

begin_define
define|#
directive|define
name|USHORT
value|unsigned short
end_define

begin_define
define|#
directive|define
name|ULONG
value|unsigned long
end_define

begin_comment
comment|/* Segment request structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|qic_segment
block|{
name|ULONG
name|sg_trk
decl_stmt|;
comment|/* Track number */
name|ULONG
name|sg_seg
decl_stmt|;
comment|/* Segment number */
name|ULONG
name|sg_crcmap
decl_stmt|;
comment|/* Returned bitmap of CRC errors */
name|ULONG
name|sg_badmap
decl_stmt|;
comment|/* Map of known bad sectors */
name|UCHAR
modifier|*
name|sg_data
decl_stmt|;
comment|/* Segment w/bad blocks discarded */
block|}
name|QIC_Segment
typedef|;
end_typedef

begin_comment
comment|/* Tape geometry structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|qic_geom
block|{
name|int
name|g_fmtno
decl_stmt|;
comment|/* Format number */
name|int
name|g_lenno
decl_stmt|;
comment|/* Length number */
name|char
name|g_fmtdesc
index|[
literal|16
index|]
decl_stmt|;
comment|/* Format text description */
name|char
name|g_lendesc
index|[
literal|16
index|]
decl_stmt|;
comment|/* Length text description */
name|int
name|g_trktape
decl_stmt|;
comment|/* Number of tracks per tape */
name|int
name|g_segtrk
decl_stmt|;
comment|/* Number of segments per track */
name|int
name|g_blktrk
decl_stmt|;
comment|/* Number of blocks per track */
name|int
name|g_fdtrk
decl_stmt|;
comment|/* Floppy disk tracks */
name|int
name|g_fdside
decl_stmt|;
comment|/* Floppy disk sectors/side */
block|}
name|QIC_Geom
typedef|;
end_typedef

begin_comment
comment|/* Tape hardware info */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|qic_hwinfo
block|{
name|int
name|hw_make
decl_stmt|;
comment|/* 10-bit drive make */
name|int
name|hw_model
decl_stmt|;
comment|/* 6-bit model */
name|int
name|hw_rombeta
decl_stmt|;
comment|/* TRUE if beta rom */
name|int
name|hw_romid
decl_stmt|;
comment|/* 8-bit rom ID */
block|}
name|QIC_HWInfo
typedef|;
end_typedef

begin_comment
comment|/* Various ioctl() routines. */
end_comment

begin_define
define|#
directive|define
name|QIOREAD
value|_IOWR('q', 1, QIC_Segment)
end_define

begin_comment
comment|/* Read segment     */
end_comment

begin_define
define|#
directive|define
name|QIOWRITE
value|_IOW('q', 2, QIC_Segment)
end_define

begin_comment
comment|/* Write segment    */
end_comment

begin_define
define|#
directive|define
name|QIOREWIND
value|_IO('q', 3)
end_define

begin_comment
comment|/* Rewind tape      */
end_comment

begin_define
define|#
directive|define
name|QIOBOT
value|_IO('q', 4)
end_define

begin_comment
comment|/* Seek beg of trk  */
end_comment

begin_define
define|#
directive|define
name|QIOEOT
value|_IO('q', 5)
end_define

begin_comment
comment|/* Seek end of trk  */
end_comment

begin_define
define|#
directive|define
name|QIOTRACK
value|_IOW('q', 6, int)
end_define

begin_comment
comment|/* Seek to track    */
end_comment

begin_define
define|#
directive|define
name|QIOSEEKLP
value|_IO('q', 7)
end_define

begin_comment
comment|/* Seek load point  */
end_comment

begin_define
define|#
directive|define
name|QIOFORWARD
value|_IO('q', 8)
end_define

begin_comment
comment|/* Move tape fwd    */
end_comment

begin_define
define|#
directive|define
name|QIOSTOP
value|_IO('q', 9)
end_define

begin_comment
comment|/* Stop tape	    */
end_comment

begin_define
define|#
directive|define
name|QIOPRIMARY
value|_IO('q', 10)
end_define

begin_comment
comment|/* Primary mode     */
end_comment

begin_define
define|#
directive|define
name|QIOFORMAT
value|_IO('q', 11)
end_define

begin_comment
comment|/* Format mode      */
end_comment

begin_define
define|#
directive|define
name|QIOVERIFY
value|_IO('q', 12)
end_define

begin_comment
comment|/* Verify mode      */
end_comment

begin_define
define|#
directive|define
name|QIOWRREF
value|_IO('q', 13)
end_define

begin_comment
comment|/* Write ref burst  */
end_comment

begin_define
define|#
directive|define
name|QIOSTATUS
value|_IOR('q', 14, int)
end_define

begin_comment
comment|/* Get drive status */
end_comment

begin_define
define|#
directive|define
name|QIOCONFIG
value|_IOR('q', 15, int)
end_define

begin_comment
comment|/* Get tape config  */
end_comment

begin_define
define|#
directive|define
name|QIOGEOM
value|_IOR('q', 16, QIC_Geom)
end_define

begin_comment
comment|/* Get geometry	    */
end_comment

begin_define
define|#
directive|define
name|QIOHWINFO
value|_IOR('q', 17, QIC_HWInfo)
end_define

begin_comment
comment|/* Get hardware inf */
end_comment

begin_define
define|#
directive|define
name|QIOSENDHDR
value|_IOW('q', 18, QIC_Segment)
end_define

begin_comment
comment|/* Send header      */
end_comment

begin_define
define|#
directive|define
name|QIORECVHDR
value|_IOWR('q', 19, QIC_Segment)
end_define

begin_comment
comment|/* Receive header   */
end_comment

begin_comment
comment|/* QIC drive status bits. */
end_comment

begin_define
define|#
directive|define
name|QS_READY
value|0x01
end_define

begin_comment
comment|/* Drive ready */
end_comment

begin_define
define|#
directive|define
name|QS_ERROR
value|0x02
end_define

begin_comment
comment|/* Error detected */
end_comment

begin_define
define|#
directive|define
name|QS_CART
value|0x04
end_define

begin_comment
comment|/* Tape in drive */
end_comment

begin_define
define|#
directive|define
name|QS_RDONLY
value|0x08
end_define

begin_comment
comment|/* Write protect */
end_comment

begin_define
define|#
directive|define
name|QS_NEWCART
value|0x10
end_define

begin_comment
comment|/* New tape inserted */
end_comment

begin_define
define|#
directive|define
name|QS_FMTOK
value|0x20
end_define

begin_comment
comment|/* Tape is formatted */
end_comment

begin_define
define|#
directive|define
name|QS_BOT
value|0x40
end_define

begin_comment
comment|/* Tape at beginning */
end_comment

begin_define
define|#
directive|define
name|QS_EOT
value|0x80
end_define

begin_comment
comment|/* Tape at end */
end_comment

begin_comment
comment|/* QIC configuration bits. */
end_comment

begin_define
define|#
directive|define
name|QCF_RTMASK
value|0x18
end_define

begin_comment
comment|/* Rate mask */
end_comment

begin_define
define|#
directive|define
name|QCF_RT250
value|0x00
end_define

begin_comment
comment|/* 250K bps */
end_comment

begin_define
define|#
directive|define
name|QCF_RT2
value|0x01
end_define

begin_comment
comment|/* 2M bps */
end_comment

begin_define
define|#
directive|define
name|QCF_RT500
value|0x02
end_define

begin_comment
comment|/* 500K bps */
end_comment

begin_define
define|#
directive|define
name|QCF_RT1
value|0x03
end_define

begin_comment
comment|/* 1M bps */
end_comment

begin_define
define|#
directive|define
name|QCF_EXTRA
value|0x40
end_define

begin_comment
comment|/* Extra length tape */
end_comment

begin_define
define|#
directive|define
name|QCF_QIC80
value|0x80
end_define

begin_comment
comment|/* QIC-80 detected */
end_comment

begin_comment
comment|/* QIC tape status bits. */
end_comment

begin_define
define|#
directive|define
name|QTS_FMMASK
value|0x0f
end_define

begin_comment
comment|/* Tape format mask */
end_comment

begin_define
define|#
directive|define
name|QTS_LNMASK
value|0xf0
end_define

begin_comment
comment|/* Tape length mask */
end_comment

begin_define
define|#
directive|define
name|QTS_QIC40
value|0x01
end_define

begin_comment
comment|/* QIC-40 tape */
end_comment

begin_define
define|#
directive|define
name|QTS_QIC80
value|0x02
end_define

begin_comment
comment|/* QIC-80 tape */
end_comment

begin_define
define|#
directive|define
name|QTS_QIC500
value|0x03
end_define

begin_comment
comment|/* QIC-500 tape */
end_comment

begin_define
define|#
directive|define
name|QTS_LEN1
value|0x10
end_define

begin_comment
comment|/* 205 ft/550 Oe */
end_comment

begin_define
define|#
directive|define
name|QTS_LEN2
value|0x20
end_define

begin_comment
comment|/* 307.5 ft/550 Oe */
end_comment

begin_define
define|#
directive|define
name|QTS_LEN3
value|0x30
end_define

begin_comment
comment|/* 295 ft/900 Oe */
end_comment

begin_define
define|#
directive|define
name|QTS_LEN4
value|0x40
end_define

begin_comment
comment|/* 1100 ft/550 Oe */
end_comment

begin_define
define|#
directive|define
name|QTS_LEN5
value|0x50
end_define

begin_comment
comment|/* 1100 ft/900 Oe */
end_comment

begin_comment
comment|/* Tape header segment structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|qic_header
block|{
name|ULONG
name|qh_sig
decl_stmt|;
comment|/* Header signature 0x55aa55aa */
name|UCHAR
name|qh_fmtc
decl_stmt|;
comment|/* Format code */
name|UCHAR
name|qh_unused1
decl_stmt|;
name|USHORT
name|qh_hseg
decl_stmt|;
comment|/* Header segment number */
name|USHORT
name|qh_dhseg
decl_stmt|;
comment|/* Duplicate header segment number */
name|USHORT
name|qh_first
decl_stmt|;
comment|/* First logical area data segment */
name|USHORT
name|qh_last
decl_stmt|;
comment|/* Last logical area data segment */
name|UCHAR
name|qh_fmtdate
index|[
literal|4
index|]
decl_stmt|;
comment|/* Most recent format date */
name|UCHAR
name|qh_chgdate
index|[
literal|4
index|]
decl_stmt|;
comment|/* Most recent tape change date */
name|UCHAR
name|qh_unused2
index|[
literal|2
index|]
decl_stmt|;
name|USHORT
name|qh_tstrk
decl_stmt|;
comment|/* Tape segments per track */
name|UCHAR
name|qh_ttcart
decl_stmt|;
comment|/* Tape tracks per cartridge */
name|UCHAR
name|qh_mfside
decl_stmt|;
comment|/* Max floppy sides */
name|UCHAR
name|qh_mftrk
decl_stmt|;
comment|/* Max floppy tracks */
name|UCHAR
name|qh_mfsect
decl_stmt|;
comment|/* Max floppy sector */
name|char
name|qh_tname
index|[
literal|44
index|]
decl_stmt|;
comment|/* Tape name (ASCII, space filled) */
name|UCHAR
name|qh_namdate
index|[
literal|4
index|]
decl_stmt|;
comment|/* Date tape was given a name */
name|USHORT
name|qh_cprseg
decl_stmt|;
comment|/* Compression map start segment */
name|UCHAR
name|qh_unused3
index|[
literal|48
index|]
decl_stmt|;
name|UCHAR
name|qh_refmt
decl_stmt|;
comment|/* Re-format flag */
name|UCHAR
name|qh_unused4
decl_stmt|;
name|UCHAR
name|qh_iocount
index|[
literal|4
index|]
decl_stmt|;
comment|/* I/O count for life of tape */
name|UCHAR
name|qh_unused5
index|[
literal|4
index|]
decl_stmt|;
name|UCHAR
name|qh_ffmtdate
index|[
literal|4
index|]
decl_stmt|;
comment|/* Date first formatted */
name|USHORT
name|qh_fmtcount
decl_stmt|;
comment|/* Number of times formatted */
name|USHORT
name|qh_badsect
decl_stmt|;
comment|/* Failed sector count */
name|char
name|qh_mfname
index|[
literal|44
index|]
decl_stmt|;
comment|/* Manufacturer name if pre-formatted */
name|char
name|qh_mflot
index|[
literal|44
index|]
decl_stmt|;
comment|/* Manufacturer lot code */
name|UCHAR
name|qh_unused6
index|[
literal|22
index|]
decl_stmt|;
name|ULONG
name|qh_fail
index|[
literal|448
index|]
decl_stmt|;
comment|/* Failed sector log */
name|ULONG
name|qh_badmap
index|[
literal|6912
index|]
decl_stmt|;
comment|/* Bad sector map */
block|}
name|QIC_Header
typedef|;
end_typedef

begin_comment
comment|/* Volume table of contents entry structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|qic_vtbl
block|{
name|UCHAR
name|vt_sig
index|[
literal|4
index|]
decl_stmt|;
comment|/* Signature "VTBL" if entry used */
name|USHORT
name|vt_first
decl_stmt|;
comment|/* Starting segment */
name|USHORT
name|vt_last
decl_stmt|;
comment|/* Ending segment */
name|char
name|vt_vname
index|[
literal|44
index|]
decl_stmt|;
comment|/* Set name */
name|UCHAR
name|vt_savdate
index|[
literal|4
index|]
decl_stmt|;
comment|/* Date saved */
name|UCHAR
name|vt_flags
decl_stmt|;
comment|/* Volume flags */
name|UCHAR
name|vt_multi
decl_stmt|;
comment|/* Multi cartridge sequence no. */
name|UCHAR
name|vt_vext
index|[
literal|26
index|]
decl_stmt|;
comment|/* Extension data */
name|char
name|vt_passwd
index|[
literal|8
index|]
decl_stmt|;
comment|/* Password for volume */
name|UCHAR
name|vt_dirsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* Directory section size */
name|UCHAR
name|vt_dtasize
index|[
literal|4
index|]
decl_stmt|;
comment|/* Data section size */
name|USHORT
name|vt_osver
decl_stmt|;
comment|/* Operating System version */
name|char
name|vt_label
index|[
literal|16
index|]
decl_stmt|;
comment|/* Source drive label */
name|UCHAR
name|vt_ldev
decl_stmt|;
comment|/* Logical device origin */
name|UCHAR
name|vt_pdev
decl_stmt|;
comment|/* Physical device origin */
name|UCHAR
name|vt_cprtype
decl_stmt|;
comment|/* Compression type */
name|UCHAR
name|vt_ostype
decl_stmt|;
comment|/* Operating System type */
name|UCHAR
name|vt_ostype2
decl_stmt|;
comment|/* Always zero ?? */
name|UCHAR
name|vt_isocpr
decl_stmt|;
comment|/* ISO compression type */
name|UCHAR
name|vt_unused1
index|[
literal|4
index|]
decl_stmt|;
block|}
name|QIC_VTbl
typedef|;
end_typedef

begin_comment
comment|/* Data compression map structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|qic_dcmap
block|{
name|UCHAR
name|dc_sig
index|[
literal|4
index|]
decl_stmt|;
comment|/* Signature "DCMS" */
name|USHORT
name|dc_mlen
decl_stmt|;
comment|/* Total map length */
name|UCHAR
name|dc_unused1
index|[
literal|6
index|]
decl_stmt|;
name|ULONG
name|dc_offset
index|[
literal|7421
index|]
decl_stmt|;
comment|/* Byte offsets to segments */
block|}
name|QIC_DCMap
typedef|;
end_typedef

begin_comment
comment|/* System specific file set structures - Unix */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|qic_unix_set
block|{
name|UCHAR
name|fsu_perm
decl_stmt|;
comment|/* Permissions */
name|UCHAR
name|fsu_attr2
decl_stmt|;
comment|/* More attributes */
name|UCHAR
name|fsu_ctime
index|[
literal|4
index|]
decl_stmt|;
comment|/* Creation time */
name|UCHAR
name|fsu_atime
index|[
literal|4
index|]
decl_stmt|;
comment|/* Last access time */
name|UCHAR
name|fsu_inode
index|[
literal|4
index|]
decl_stmt|;
comment|/* i-node number */
name|UCHAR
name|fsu_user
index|[
literal|4
index|]
decl_stmt|;
comment|/* User number */
name|UCHAR
name|fsu_group
index|[
literal|4
index|]
decl_stmt|;
comment|/* Group number */
name|UCHAR
name|fsu_major
decl_stmt|;
comment|/* Major device number */
name|UCHAR
name|fsu_minor
decl_stmt|;
comment|/* Minor device number */
name|UCHAR
name|fsu_nsize
decl_stmt|;
comment|/* Name size */
name|UCHAR
name|fsu_name
decl_stmt|;
comment|/* Entry name starts here */
block|}
name|QIC_Unix_Set
typedef|;
end_typedef

begin_comment
comment|/* File set structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|qic_fileset
block|{
name|UCHAR
name|fs_size
decl_stmt|;
comment|/* Size of fixed + system size - 1 */
name|UCHAR
name|fs_attr
decl_stmt|;
comment|/* Attributes */
name|UCHAR
name|fs_mtime
decl_stmt|;
comment|/* Modification time */
name|UCHAR
name|fs_dsize
index|[
literal|4
index|]
decl_stmt|;
comment|/* Data size */
block|}
name|QIC_FileSet
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_FTAPE_H_ */
end_comment

end_unit

