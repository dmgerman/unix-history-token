begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * crtstub : stubs for displays not linked into the server  */
end_comment

begin_include
include|#
directive|include
file|"X.h"
end_include

begin_include
include|#
directive|include
file|"scrnintstr.h"
end_include

begin_function
specifier|static
name|void
name|notinstalled
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|printf
argument_list|(
literal|"%s is not installed in server\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"Run ??? to install the display"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|ScreenInit
parameter_list|(
name|ScreenInitRoutine
parameter_list|,
name|msg
parameter_list|)
define|\
comment|/* Bool */
define|\
value|ScreenInitRoutine(index, pScreen, argc,argv)  \ 	int index, argc; ScreenPtr pScreen; char **argv; \   { notinstalled(msg); return 0; }
end_define

begin_define
define|#
directive|define
name|ScreenInfo
parameter_list|(
name|ScreenInfoRoutine
parameter_list|,
name|msg
parameter_list|)
define|\
comment|/* Bool */
define|\
value|ScreenInfoRoutine(index, argv,argc)		\ 	int index, argc; char **argv;		\   { notinstalled(msg); return 0; }
end_define

begin_comment
comment|/*--------------------------------------------------------------------*/
end_comment

begin_macro
name|ScreenInit
argument_list|(
argument|mobScreenInit
argument_list|,
literal|"Moberly"
argument_list|)
end_macro

begin_macro
name|ScreenInfo
argument_list|(
argument|mobScreenInfo
argument_list|,
literal|"Moberly"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------*/
end_comment

begin_macro
name|ScreenInit
argument_list|(
argument|gbxScreenInit
argument_list|,
literal|"Gator Box"
argument_list|)
end_macro

begin_macro
name|ScreenInfo
argument_list|(
argument|gbxScreenInfo
argument_list|,
literal|"Gator Box"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------*/
end_comment

begin_macro
name|ScreenInit
argument_list|(
argument|mrtopcatScreenInit
argument_list|,
literal|"mrtopcat"
argument_list|)
end_macro

begin_macro
name|ScreenInfo
argument_list|(
argument|mrtopcatScreenInfo
argument_list|,
literal|"mrtopcat"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------*/
end_comment

begin_macro
name|ScreenInit
argument_list|(
argument|renScreenInit
argument_list|,
literal|"Renaissance"
argument_list|)
end_macro

begin_macro
name|ScreenInfo
argument_list|(
argument|renScreenInfo
argument_list|,
literal|"Renaissance"
argument_list|)
end_macro

begin_macro
name|ScreenInit
argument_list|(
argument|orenScreenInit
argument_list|,
literal|"Renaissance"
argument_list|)
end_macro

begin_macro
name|ScreenInfo
argument_list|(
argument|orenScreenInfo
argument_list|,
literal|"Renaissance"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------*/
end_comment

begin_macro
name|ScreenInit
argument_list|(
argument|davinciScreenInit
argument_list|,
literal|"DaVinci"
argument_list|)
end_macro

begin_macro
name|ScreenInfo
argument_list|(
argument|davinciScreenInfo
argument_list|,
literal|"DaVinci"
argument_list|)
end_macro

begin_macro
name|ScreenInit
argument_list|(
argument|oDavinciScreenInit
argument_list|,
literal|"DaVinci"
argument_list|)
end_macro

begin_macro
name|ScreenInit
argument_list|(
argument|sbDavinciScreenInit
argument_list|,
literal|"DaVinci"
argument_list|)
end_macro

begin_macro
name|ScreenInfo
argument_list|(
argument|oDavinciScreenInfo
argument_list|,
literal|"DaVinci"
argument_list|)
end_macro

begin_comment
comment|/*--------------------------------------------------------------------*/
end_comment

end_unit

