begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * extensions to ioctl_meteor.h for the bt848 cards  */
end_comment

begin_comment
comment|/*  * frequency sets  */
end_comment

begin_define
define|#
directive|define
name|CHNLSET_NABCST
value|1
end_define

begin_define
define|#
directive|define
name|CHNLSET_CABLEIRC
value|2
end_define

begin_define
define|#
directive|define
name|CHNLSET_CABLEHRC
value|3
end_define

begin_define
define|#
directive|define
name|CHNLSET_WEUROPE
value|4
end_define

begin_define
define|#
directive|define
name|CHNLSET_JPNBCST
value|5
end_define

begin_define
define|#
directive|define
name|CHNLSET_JPNCABLE
value|6
end_define

begin_define
define|#
directive|define
name|CHNLSET_MIN
value|CHNLSET_NABCST
end_define

begin_define
define|#
directive|define
name|CHNLSET_MAX
value|CHNLSET_JPNCABLE
end_define

begin_comment
comment|/*  * constants for various tuner registers  */
end_comment

begin_define
define|#
directive|define
name|BT848_HUEMIN
value|(-90)
end_define

begin_define
define|#
directive|define
name|BT848_HUEMAX
value|90
end_define

begin_define
define|#
directive|define
name|BT848_HUECENTER
value|0
end_define

begin_define
define|#
directive|define
name|BT848_HUERANGE
value|179.3
end_define

begin_define
define|#
directive|define
name|BT848_HUEREGMIN
value|(-128)
end_define

begin_define
define|#
directive|define
name|BT848_HUEREGMAX
value|127
end_define

begin_define
define|#
directive|define
name|BT848_HUESTEPS
value|256
end_define

begin_define
define|#
directive|define
name|BT848_BRIGHTMIN
value|(-50)
end_define

begin_define
define|#
directive|define
name|BT848_BRIGHTMAX
value|50
end_define

begin_define
define|#
directive|define
name|BT848_BRIGHTCENTER
value|0
end_define

begin_define
define|#
directive|define
name|BT848_BRIGHTRANGE
value|99.6
end_define

begin_define
define|#
directive|define
name|BT848_BRIGHTREGMIN
value|(-128)
end_define

begin_define
define|#
directive|define
name|BT848_BRIGHTREGMAX
value|127
end_define

begin_define
define|#
directive|define
name|BT848_BRIGHTSTEPS
value|256
end_define

begin_define
define|#
directive|define
name|BT848_CONTRASTMIN
value|0
end_define

begin_define
define|#
directive|define
name|BT848_CONTRASTMAX
value|237
end_define

begin_define
define|#
directive|define
name|BT848_CONTRASTCENTER
value|100
end_define

begin_define
define|#
directive|define
name|BT848_CONTRASTRANGE
value|236.57
end_define

begin_define
define|#
directive|define
name|BT848_CONTRASTREGMIN
value|0
end_define

begin_define
define|#
directive|define
name|BT848_CONTRASTREGMAX
value|511
end_define

begin_define
define|#
directive|define
name|BT848_CONTRASTSTEPS
value|512
end_define

begin_define
define|#
directive|define
name|BT848_CHROMAMIN
value|0
end_define

begin_define
define|#
directive|define
name|BT848_CHROMAMAX
value|284
end_define

begin_define
define|#
directive|define
name|BT848_CHROMACENTER
value|100
end_define

begin_define
define|#
directive|define
name|BT848_CHROMARANGE
value|283.89
end_define

begin_define
define|#
directive|define
name|BT848_CHROMAREGMIN
value|0
end_define

begin_define
define|#
directive|define
name|BT848_CHROMAREGMAX
value|511
end_define

begin_define
define|#
directive|define
name|BT848_CHROMASTEPS
value|512
end_define

begin_define
define|#
directive|define
name|BT848_SATUMIN
value|0
end_define

begin_define
define|#
directive|define
name|BT848_SATUMAX
value|202
end_define

begin_define
define|#
directive|define
name|BT848_SATUCENTER
value|100
end_define

begin_define
define|#
directive|define
name|BT848_SATURANGE
value|201.18
end_define

begin_define
define|#
directive|define
name|BT848_SATUREGMIN
value|0
end_define

begin_define
define|#
directive|define
name|BT848_SATUREGMAX
value|511
end_define

begin_define
define|#
directive|define
name|BT848_SATUSTEPS
value|512
end_define

begin_define
define|#
directive|define
name|BT848_SATVMIN
value|0
end_define

begin_define
define|#
directive|define
name|BT848_SATVMAX
value|284
end_define

begin_define
define|#
directive|define
name|BT848_SATVCENTER
value|100
end_define

begin_define
define|#
directive|define
name|BT848_SATVRANGE
value|283.89
end_define

begin_define
define|#
directive|define
name|BT848_SATVREGMIN
value|0
end_define

begin_define
define|#
directive|define
name|BT848_SATVREGMAX
value|511
end_define

begin_define
define|#
directive|define
name|BT848_SATVSTEPS
value|512
end_define

begin_comment
comment|/*  * audio stuff  */
end_comment

begin_define
define|#
directive|define
name|AUDIO_TUNER
value|0x00
end_define

begin_comment
comment|/* command for the audio routine */
end_comment

begin_define
define|#
directive|define
name|AUDIO_EXTERN
value|0x01
end_define

begin_comment
comment|/* don't confuse them with bit */
end_comment

begin_define
define|#
directive|define
name|AUDIO_INTERN
value|0x02
end_define

begin_comment
comment|/* settings */
end_comment

begin_define
define|#
directive|define
name|AUDIO_MUTE
value|0x80
end_define

begin_define
define|#
directive|define
name|AUDIO_UNMUTE
value|0x81
end_define

begin_comment
comment|/*  * EEProm stuff  */
end_comment

begin_struct
struct|struct
name|eeProm
block|{
name|short
name|offset
decl_stmt|;
name|short
name|count
decl_stmt|;
name|u_char
name|bytes
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * XXX: this is a hack, should be in ioctl_meteor.h  * here to avoid touching that file for now...  */
end_comment

begin_define
define|#
directive|define
name|TVTUNER_SETCHNL
value|_IOW('x', 32, unsigned int)
end_define

begin_comment
comment|/* set channel */
end_comment

begin_define
define|#
directive|define
name|TVTUNER_GETCHNL
value|_IOR('x', 32, unsigned int)
end_define

begin_comment
comment|/* get channel */
end_comment

begin_define
define|#
directive|define
name|TVTUNER_SETTYPE
value|_IOW('x', 33, unsigned int)
end_define

begin_comment
comment|/* set tuner type */
end_comment

begin_define
define|#
directive|define
name|TVTUNER_GETTYPE
value|_IOR('x', 33, unsigned int)
end_define

begin_comment
comment|/* get tuner type */
end_comment

begin_define
define|#
directive|define
name|TVTUNER_GETSTATUS
value|_IOR('x', 34, unsigned int)
end_define

begin_comment
comment|/* get tuner status */
end_comment

begin_define
define|#
directive|define
name|TVTUNER_SETFREQ
value|_IOW('x', 35, unsigned int)
end_define

begin_comment
comment|/* set frequency */
end_comment

begin_define
define|#
directive|define
name|TVTUNER_GETFREQ
value|_IOR('x', 36, unsigned int)
end_define

begin_comment
comment|/* get frequency */
end_comment

begin_define
define|#
directive|define
name|BT848_SHUE
value|_IOW('x', 37, int)
end_define

begin_comment
comment|/* set hue */
end_comment

begin_define
define|#
directive|define
name|BT848_GHUE
value|_IOR('x', 37, int)
end_define

begin_comment
comment|/* get hue */
end_comment

begin_define
define|#
directive|define
name|BT848_SBRIG
value|_IOW('x', 38, int)
end_define

begin_comment
comment|/* set brightness */
end_comment

begin_define
define|#
directive|define
name|BT848_GBRIG
value|_IOR('x', 38, int)
end_define

begin_comment
comment|/* get brightness */
end_comment

begin_define
define|#
directive|define
name|BT848_SCSAT
value|_IOW('x', 39, int)
end_define

begin_comment
comment|/* set chroma sat */
end_comment

begin_define
define|#
directive|define
name|BT848_GCSAT
value|_IOR('x', 39, int)
end_define

begin_comment
comment|/* get UV saturation */
end_comment

begin_define
define|#
directive|define
name|BT848_SCONT
value|_IOW('x', 40, int)
end_define

begin_comment
comment|/* set contrast */
end_comment

begin_define
define|#
directive|define
name|BT848_GCONT
value|_IOR('x', 40, int)
end_define

begin_comment
comment|/* get contrast */
end_comment

begin_define
define|#
directive|define
name|BT848_SVSAT
value|_IOW('x', 41, int)
end_define

begin_comment
comment|/* set chroma V sat */
end_comment

begin_define
define|#
directive|define
name|BT848_GVSAT
value|_IOR('x', 41, int)
end_define

begin_comment
comment|/* get V saturation */
end_comment

begin_define
define|#
directive|define
name|BT848_SUSAT
value|_IOW('x', 42, int)
end_define

begin_comment
comment|/* set chroma U sat */
end_comment

begin_define
define|#
directive|define
name|BT848_GUSAT
value|_IOR('x', 42, int)
end_define

begin_comment
comment|/* get U saturation */
end_comment

begin_define
define|#
directive|define
name|BT848_SCBARS
value|_IOR('x', 43, int)
end_define

begin_comment
comment|/* set colorbar */
end_comment

begin_define
define|#
directive|define
name|BT848_CCBARS
value|_IOR('x', 44, int)
end_define

begin_comment
comment|/* clear colorbar */
end_comment

begin_define
define|#
directive|define
name|BT848_SAUDIO
value|_IOW('x', 46, int)
end_define

begin_comment
comment|/* set audio channel */
end_comment

begin_define
define|#
directive|define
name|BT848_GAUDIO
value|_IOR('x', 47, int)
end_define

begin_comment
comment|/* get audio channel */
end_comment

begin_define
define|#
directive|define
name|BT848_SBTSC
value|_IOW('x', 48, int)
end_define

begin_comment
comment|/* set audio channel */
end_comment

begin_define
define|#
directive|define
name|BT848_GSTATUS
value|_IOR('x', 49, unsigned int)
end_define

begin_comment
comment|/* reap status */
end_comment

begin_define
define|#
directive|define
name|BT848_WEEPROM
value|_IOWR('x', 50, struct eeProm)
end_define

begin_comment
comment|/* write to EEProm */
end_comment

begin_define
define|#
directive|define
name|BT848_REEPROM
value|_IOWR('x', 51, struct eeProm)
end_define

begin_comment
comment|/* read from EEProm */
end_comment

begin_define
define|#
directive|define
name|BT848_SIGNATURE
value|_IOWR('x', 52, struct eeProm)
end_define

begin_comment
comment|/* read card sig */
end_comment

begin_define
define|#
directive|define
name|TVTUNER_SETAFC
value|_IOW('x', 53, int)
end_define

begin_comment
comment|/* turn AFC on/off */
end_comment

begin_define
define|#
directive|define
name|TVTUNER_GETAFC
value|_IOR('x', 54, int)
end_define

begin_comment
comment|/* query AFC on/off */
end_comment

begin_define
define|#
directive|define
name|BT848_SLNOTCH
value|_IOW('x', 55, int)
end_define

begin_comment
comment|/* set luma notch */
end_comment

begin_define
define|#
directive|define
name|BT848_GLNOTCH
value|_IOR('x', 56, int)
end_define

begin_comment
comment|/* get luma notch */
end_comment

begin_comment
comment|/*  * XXX: more bad magic,  *      we need to fix the METEORGINPUT to return something public  *      duplicate them here for now...  */
end_comment

begin_define
define|#
directive|define
name|METEOR_DEV0
value|0x00001000
end_define

begin_define
define|#
directive|define
name|METEOR_DEV1
value|0x00002000
end_define

begin_define
define|#
directive|define
name|METEOR_DEV2
value|0x00004000
end_define

begin_comment
comment|/*  * right now I don't know were to put these, but as they are suppose to be  * a part of a common video capture interface, these should be relocated to  * another place.  Probably most of the METEOR_xxx defines need to be  * renamed and moved to a common header  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|METEOR_PIXTYPE_RGB
block|,
name|METEOR_PIXTYPE_YUV
block|,
name|METEOR_PIXTYPE_YUV_PACKED
block|,
name|METEOR_PIXTYPE_YUV_12
block|}
name|METEOR_PIXTYPE
typedef|;
end_typedef

begin_struct
struct|struct
name|meteor_pixfmt
block|{
name|u_int
name|index
decl_stmt|;
comment|/* Index in supported pixfmt list     */
name|METEOR_PIXTYPE
name|type
decl_stmt|;
comment|/* What's the board gonna feed us     */
name|u_int
name|Bpp
decl_stmt|;
comment|/* Bytes per pixel                    */
name|u_long
name|masks
index|[
literal|3
index|]
decl_stmt|;
comment|/* R,G,B or Y,U,V masks, respectively */
name|unsigned
name|swap_bytes
range|:
literal|1
decl_stmt|;
comment|/* Bytes  swapped within shorts       */
name|unsigned
name|swap_shorts
range|:
literal|1
decl_stmt|;
comment|/* Shorts swapped within longs        */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bktr_clip
block|{
name|int
name|x_min
decl_stmt|;
name|int
name|x_max
decl_stmt|;
name|int
name|y_min
decl_stmt|;
name|int
name|y_max
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BT848_MAX_CLIP_NODE
value|100
end_define

begin_struct
struct|struct
name|_bktr_clip
block|{
name|struct
name|bktr_clip
name|x
index|[
name|BT848_MAX_CLIP_NODE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * I'm using METEOR_xxx just because that will be common to other interface  * and less of a surprise  */
end_comment

begin_define
define|#
directive|define
name|METEORSACTPIXFMT
value|_IOW('x', 64, int )
end_define

begin_define
define|#
directive|define
name|METEORGACTPIXFMT
value|_IOR('x', 64, int )
end_define

begin_define
define|#
directive|define
name|METEORGSUPPIXFMT
value|_IOWR('x', 65, struct meteor_pixfmt)
end_define

begin_comment
comment|/* set clip list */
end_comment

begin_define
define|#
directive|define
name|BT848SCLIP
value|_IOW('x', 66, struct _bktr_clip )
end_define

begin_define
define|#
directive|define
name|BT848GCLIP
value|_IOR('x', 66, struct _bktr_clip )
end_define

begin_comment
comment|/* set input format */
end_comment

begin_define
define|#
directive|define
name|BT848SFMT
value|_IOW('x', 67, unsigned long )
end_define

begin_define
define|#
directive|define
name|BT848GFMT
value|_IOR('x', 67, unsigned long )
end_define

begin_comment
comment|/* Read/Write the BT848's I2C bus directly  * b7-b0:    data (read/write)  * b15-b8:   internal peripheral register (write)     * b23-b16:  i2c addr (write)  * b31-b24:  1 = write, 0 = read   */
end_comment

begin_define
define|#
directive|define
name|BT848_I2CWR
value|_IOWR('x', 57, u_long)
end_define

begin_comment
comment|/* i2c read-write */
end_comment

begin_comment
comment|/* Support for radio tuner */
end_comment

begin_define
define|#
directive|define
name|RADIO_SETMODE
value|_IOW('x', 58, unsigned int)
end_define

begin_comment
comment|/* set radio modes */
end_comment

begin_define
define|#
directive|define
name|RADIO_SETFREQ
value|_IOW('x', 59, unsigned int)
end_define

begin_comment
comment|/* set frequency   */
end_comment

begin_define
define|#
directive|define
name|RADIO_GETFREQ
value|_IOR('x', 59, unsigned int)
end_define

begin_comment
comment|/* set frequency   */
end_comment

begin_comment
comment|/*  XXX - Copied from /sys/pci/brktree_reg.h  */
end_comment

begin_define
define|#
directive|define
name|BT848_IFORM_FORMAT
value|(0x7<<0)
end_define

begin_define
define|#
directive|define
name|BT848_IFORM_F_RSVD
value|(0x7)
end_define

begin_define
define|#
directive|define
name|BT848_IFORM_F_SECAM
value|(0x6)
end_define

begin_define
define|#
directive|define
name|BT848_IFORM_F_PALN
value|(0x5)
end_define

begin_define
define|#
directive|define
name|BT848_IFORM_F_PALM
value|(0x4)
end_define

begin_define
define|#
directive|define
name|BT848_IFORM_F_PALBDGHI
value|(0x3)
end_define

begin_define
define|#
directive|define
name|BT848_IFORM_F_NTSCJ
value|(0x2)
end_define

begin_define
define|#
directive|define
name|BT848_IFORM_F_NTSCM
value|(0x1)
end_define

begin_define
define|#
directive|define
name|BT848_IFORM_F_AUTO
value|(0x0)
end_define

end_unit

