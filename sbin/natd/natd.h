begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * natd - Network Address Translation Daemon for FreeBSD.  *  * This software is provided free of charge, with no   * warranty of any kind, either expressed or implied.  * Use at your own risk.  *   * You may copy, modify and distribute this software (natd.h) freely.  *  * Ari Suutari<suutari@iki.fi>  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|PIDFILE
value|"/var/run/natd.pid"
end_define

begin_define
define|#
directive|define
name|INPUT
value|1
end_define

begin_define
define|#
directive|define
name|OUTPUT
value|2
end_define

begin_define
define|#
directive|define
name|DONT_KNOW
value|3
end_define

begin_function_decl
specifier|extern
name|void
name|Quit
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|Warn
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|SendNeedFragIcmp
parameter_list|(
name|int
name|sock
parameter_list|,
name|struct
name|ip
modifier|*
name|failedDgram
parameter_list|,
name|int
name|mtu
parameter_list|)
function_decl|;
end_function_decl

end_unit

