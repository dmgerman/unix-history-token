begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  */
end_comment

begin_include
include|#
directive|include
file|"../hpDisplays.h"
end_include

begin_comment
comment|/*  * Map of the hyperion chip in memory ...  */
end_comment

begin_typedef
typedef|typedef
name|VOLATILE
struct|struct
block|{
name|u_short
name|id_reset
decl_stmt|;
comment|/* id and reset register 	*/
comment|/* 0x01 */
name|u_char
name|filler2
decl_stmt|;
name|u_char
name|interrupts
decl_stmt|;
comment|/* interrupts			*/
comment|/* 0x03 */
name|u_char
name|filler2a
decl_stmt|;
name|u_char
name|t_memwide
decl_stmt|;
comment|/* top half frame buf width	*/
comment|/* 0x05 */
name|u_char
name|filler2b
decl_stmt|;
name|u_char
name|b_memwide
decl_stmt|;
comment|/* bottom half frame buf width	*/
comment|/* 0x07 */
name|u_char
name|filler2c
decl_stmt|;
name|u_char
name|t_memhigh
decl_stmt|;
comment|/* top half frame buf height 	*/
comment|/* 0x09 */
name|u_char
name|filler2d
decl_stmt|;
name|u_char
name|b_memhigh
decl_stmt|;
comment|/* bot half frame buf height	*/
comment|/* 0x0b */
name|u_char
name|filler2e
decl_stmt|;
name|u_char
name|t_dispwide
decl_stmt|;
comment|/* top half display width	*/
comment|/* 0x0d */
name|u_char
name|filler2f
decl_stmt|;
name|u_char
name|b_dispwide
decl_stmt|;
comment|/* bot half display width	*/
comment|/* 0x0f */
name|u_char
name|filler2g
decl_stmt|;
name|u_char
name|t_disphigh
decl_stmt|;
comment|/* top half display height	*/
comment|/* 0x11 */
name|u_char
name|filler2h
decl_stmt|;
name|u_char
name|b_disphigh
decl_stmt|;
comment|/* bot half display height	*/
comment|/* 0x13 */
name|u_char
name|filler2i
decl_stmt|;
name|u_char
name|id_second
decl_stmt|;
comment|/* secondary id 5=LCC 6=HRC 	*/
comment|/* 0x15 */
name|u_char
name|filler2j
decl_stmt|;
comment|/* 7=HRM, 9=319X		*/
name|u_char
name|bits
decl_stmt|;
comment|/* 0 square pixels, 1 double hi */
comment|/* 0x17 */
name|u_char
name|filler3
index|[
literal|0x4000
operator|-
literal|0x17
operator|-
literal|1
index|]
decl_stmt|;
name|u_char
name|nblank
decl_stmt|;
comment|/* video output enable		*/
comment|/* 0x4000 */
block|}
name|HYPER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HY_VIDEO_ON
value|0x05
end_define

begin_define
define|#
directive|define
name|HY_VIDEO_OFF
value|0x00
end_define

begin_define
define|#
directive|define
name|getHyHardware
parameter_list|(
name|pScreen
parameter_list|)
value|((HYPER *) getGpHardware(pScreen))
end_define

begin_function_decl
specifier|extern
name|void
name|hyperMoveBits
parameter_list|()
function_decl|;
end_function_decl

end_unit

