begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************ Copyright (c) 1992 by Hewlett-Packard Company, Palo Alto, California.  			All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of Hewlett-Packard not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  HEWLETT-PACKARD DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL HEWLETT-PACKARD BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ********************************************************/
end_comment

begin_comment
comment|/***************************************************************************  *  * Constants and structs for dynamically loaded serial input device drivers.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_X_SERIALDRV_H_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|hp9000
end_ifndef

begin_include
include|#
directive|include
file|<dl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MIN_KEYCODE
value|8
end_define

begin_define
define|#
directive|define
name|MAX_NM
value|64
end_define

begin_define
define|#
directive|define
name|DATA_IS_8_BITS
value|0x01
end_define

begin_define
define|#
directive|define
name|DATA_IS_16_BITS
value|0x02
end_define

begin_define
define|#
directive|define
name|DATA_IS_32_BITS
value|0x04
end_define

begin_define
define|#
directive|define
name|REPORTS_PROXIMITY
value|0x08
end_define

begin_define
define|#
directive|define
name|ABSOLUTE_DATA
value|0x040
end_define

begin_define
define|#
directive|define
name|NON_CONTIGUOUS_DATA
value|0x080
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|KEY_DATA
value|0x01
end_define

begin_define
define|#
directive|define
name|BUTTON_DATA
value|0x02
end_define

begin_define
define|#
directive|define
name|PROXIMITY_DATA
value|0x04
end_define

begin_define
define|#
directive|define
name|MOTION_DATA
value|0x08
end_define

begin_define
define|#
directive|define
name|INIT_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|INIT_FAILURE
value|1
end_define

begin_define
define|#
directive|define
name|READ_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|READ_FAILURE
value|1
end_define

begin_define
define|#
directive|define
name|WRITE_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|WRITE_FAILURE
value|1
end_define

begin_define
define|#
directive|define
name|CLOSE_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|IN_PROXIMITY
value|0
end_define

begin_define
define|#
directive|define
name|OUT_OF_PROXIMITY
value|1
end_define

begin_define
define|#
directive|define
name|_XSetDeviceMode
value|0
end_define

begin_define
define|#
directive|define
name|_XSetDeviceValuators
value|1
end_define

begin_define
define|#
directive|define
name|_XChangeDeviceControl
value|2
end_define

begin_define
define|#
directive|define
name|_XChangeFeedbackControl
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|class
decl_stmt|;
name|int
name|led_mask
decl_stmt|;
name|int
name|led_values
decl_stmt|;
block|}
name|HPLedFeedbackControl
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
modifier|*
name|valuators
decl_stmt|;
name|int
name|first_valuator
decl_stmt|;
name|int
name|num_valuators
decl_stmt|;
block|}
name|HPValuatorControl
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
modifier|*
name|resolutions
decl_stmt|;
name|int
name|first_valuator
decl_stmt|;
name|int
name|num_valuators
decl_stmt|;
block|}
name|HPResolutionControl
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|pfrb
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|ConfigureProc
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|InitProc
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|ReadProc
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|WriteProc
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|CloseProc
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SerialProcs
block|{
name|char
modifier|*
name|x_name
decl_stmt|;
comment|/* filled in by driver		*/
name|ConfigureProc
name|configure
decl_stmt|;
comment|/* filled in by driver		*/
name|ReadProc
name|read
decl_stmt|;
comment|/* filled in by driver		*/
name|WriteProc
name|write
decl_stmt|;
comment|/* filled in by driver		*/
name|CloseProc
name|close
decl_stmt|;
comment|/* filled in by driver		*/
ifndef|#
directive|ifndef
name|hp9000
name|shl_t
name|ldr_module_id
decl_stmt|;
comment|/* filled in by X server	*/
endif|#
directive|endif
name|int
name|fd
decl_stmt|;
comment|/* filled in by X server	*/
name|char
name|driver_name
index|[
name|MAX_NM
index|]
decl_stmt|;
comment|/* filled in by X server	*/
block|}
name|SerialProcs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_HPInputDeviceHeader
block|{
name|char
name|path
index|[
name|MAX_NM
index|]
decl_stmt|;
comment|/* device path - filled in by X server  */
name|int
name|resolution
decl_stmt|;
comment|/* resolution in counts/cm         	*/
name|int
name|max_x
decl_stmt|;
comment|/* maximum x value in counts    	*/
name|int
name|max_y
decl_stmt|;
comment|/* maximum y value in counts    	*/
name|int
name|file_ds
decl_stmt|;
comment|/* file descriptor              	*/
name|u_char
name|flags
decl_stmt|;
comment|/* device characteristics		*/
name|u_char
name|ax_num
decl_stmt|;
comment|/* number of axes			*/
name|u_char
name|num_buttons
decl_stmt|;
comment|/* number of buttons         		*/
name|u_char
name|num_keys
decl_stmt|;
comment|/* number of keys            		*/
name|u_char
name|min_kcode
decl_stmt|;
comment|/* minimum keycode           		*/
name|u_char
name|max_kcode
decl_stmt|;
comment|/* maximum keycode           		*/
name|u_char
name|num_leds
decl_stmt|;
comment|/* number of leds               	*/
block|}
name|HPInputDeviceHeader
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _X_SERIALDRV_H_ */
end_comment

end_unit

