begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  solFb.h --   *  *	remade by A.Fujita, DEC-16-1992  */
end_comment

begin_include
include|#
directive|include
file|<luna68k/dev/fbio.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|_SolFbProc
block|{
name|int
function_decl|(
modifier|*
name|CreateProc
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|InitProc
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|GiveUpProc
function_decl|)
parameter_list|()
function_decl|;
block|}
name|SolFbProc
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SolFbInfo
block|{
name|int
name|fb_type
decl_stmt|;
name|int
name|fb_width
decl_stmt|;
name|int
name|fb_height
decl_stmt|;
name|int
name|fb_depth
decl_stmt|;
name|int
name|scr_width
decl_stmt|;
name|int
name|scr_height
decl_stmt|;
name|char
modifier|*
name|plane
decl_stmt|;
comment|/* BitMap Plane 1   [0xB10C0008] */
name|int
name|fbfd
decl_stmt|;
comment|/* /dev/fb */
name|int
name|fbmapsize
decl_stmt|;
comment|/* frame buffer mapping size   */
name|char
modifier|*
name|fbmap
decl_stmt|;
comment|/* frame buffer mapping addres */
name|SolFbProc
modifier|*
name|func
decl_stmt|;
block|}
name|SolFbInfo
operator|,
typedef|*
name|SolFbInfoPtr
typedef|;
end_typedef

begin_comment
comment|/*	fb_type		*/
end_comment

begin_define
define|#
directive|define
name|FB_BM
value|0
end_define

begin_comment
comment|/* scr_width and scr_height */
end_comment

begin_define
define|#
directive|define
name|SCREEN_WIDTH
value|1280
end_define

begin_define
define|#
directive|define
name|SCREEN_HEIGHT
value|1024
end_define

begin_comment
comment|/* fb_width and fb_height */
end_comment

begin_define
define|#
directive|define
name|FB_WIDTH
value|2048
end_define

begin_define
define|#
directive|define
name|FB_HEIGHT
value|1024
end_define

begin_define
define|#
directive|define
name|COLOR_TV_RESOLUTION
value|110
end_define

begin_define
define|#
directive|define
name|MONO_TV_RESOLUTION
value|125
end_define

begin_comment
comment|/* **	frame buffer memory memory map */
end_comment

begin_struct
struct|struct
name|bm_one_data
block|{
comment|/* mono frame buffer */
name|int
name|sd
index|[
literal|1
index|]
index|[
literal|1024
index|]
index|[
literal|64
index|]
decl_stmt|;
comment|/* 2048 x 1024 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bm_eight_data
block|{
comment|/* 8 depth color frame buffer */
name|int
name|sd
index|[
literal|8
index|]
index|[
literal|1024
index|]
index|[
literal|64
index|]
decl_stmt|;
comment|/* 2048 x 1024 x 8 */
block|}
struct|;
end_struct

begin_comment
comment|/* ** luna raster operateon hardware memory map */
end_comment

begin_union
union|union
name|bm_function_set
block|{
name|long
name|op_cont
index|[
literal|16
index|]
decl_stmt|;
comment|/* function set register */
name|char
name|pad
index|[
literal|0x40000
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* **	luna graphic display control hardware mememory map  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|sol_bm_fbmap
block|{
union|union
block|{
name|long
name|reg
decl_stmt|;
name|char
name|pad2
index|[
literal|0x40000
index|]
decl_stmt|;
block|}
name|refresh
union|;
comment|/* display area control register (write only) */
union|union
block|{
name|long
name|reg
decl_stmt|;
name|char
name|pad3
index|[
literal|0x40000
index|]
decl_stmt|;
block|}
name|pselect
union|;
comment|/* plane select register (write only) */
name|struct
name|bm_one_data
name|cbmplane
decl_stmt|;
comment|/* common frame buffer (write only) */
name|struct
name|bm_eight_data
name|bmplane
decl_stmt|;
comment|/* frame buffer (read/write) */
name|union
name|bm_function_set
name|cplane
decl_stmt|;
comment|/* luna raster operateon hardware (common frame buffer)  */
name|union
name|bm_function_set
name|planes
index|[
literal|8
index|]
decl_stmt|;
comment|/* luna raster operateon hardware */
block|}
typedef|*
name|SolBmMapPtr
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|Bool
name|solBmCreate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|solBmInit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|solBmGiveUp
parameter_list|()
function_decl|;
end_function_decl

end_unit

