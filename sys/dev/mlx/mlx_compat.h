begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000, 2001 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Portability and compatibility interfaces.  */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500003
end_if

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_define
define|#
directive|define
name|INTR_ENTROPY
value|0
end_define

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_comment
comment|/* old buf style */
end_comment

begin_typedef
typedef|typedef
name|struct
name|buf
name|mlx_bio
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|buf_queue_head
name|mlx_bioq
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MLX_BIO_QINIT
parameter_list|(
name|bq
parameter_list|)
value|bufq_init(&bq);
end_define

begin_define
define|#
directive|define
name|MLX_BIO_QINSERT
parameter_list|(
name|bq
parameter_list|,
name|bp
parameter_list|)
value|bufq_insert_tail(&bq, bp)
end_define

begin_define
define|#
directive|define
name|MLX_BIO_QFIRST
parameter_list|(
name|bq
parameter_list|)
value|bufq_first(&bq)
end_define

begin_define
define|#
directive|define
name|MLX_BIO_QREMOVE
parameter_list|(
name|bq
parameter_list|,
name|bp
parameter_list|)
value|bufq_remove(&bq, bp)
end_define

begin_define
define|#
directive|define
name|MLX_BIO_IS_READ
parameter_list|(
name|bp
parameter_list|)
value|((bp)->b_flags& B_READ)
end_define

begin_define
define|#
directive|define
name|MLX_BIO_DATA
parameter_list|(
name|bp
parameter_list|)
value|(bp)->b_data
end_define

begin_define
define|#
directive|define
name|MLX_BIO_LENGTH
parameter_list|(
name|bp
parameter_list|)
value|(bp)->b_bcount
end_define

begin_define
define|#
directive|define
name|MLX_BIO_LBA
parameter_list|(
name|bp
parameter_list|)
value|(bp)->b_pblkno
end_define

begin_define
define|#
directive|define
name|MLX_BIO_SOFTC
parameter_list|(
name|bp
parameter_list|)
value|(bp)->b_dev->si_drv1
end_define

begin_define
define|#
directive|define
name|MLX_BIO_UNIT
parameter_list|(
name|bp
parameter_list|)
value|*(int *)((bp)->b_dev->si_drv2)
end_define

begin_define
define|#
directive|define
name|MLX_BIO_SET_ERROR
parameter_list|(
name|bp
parameter_list|,
name|err
parameter_list|)
value|do { (bp)->b_error = err; (bp)->b_flags |= B_ERROR;} while(0)
end_define

begin_define
define|#
directive|define
name|MLX_BIO_HAS_ERROR
parameter_list|(
name|bp
parameter_list|)
value|((bp)->b_flags& B_ERROR)
end_define

begin_define
define|#
directive|define
name|MLX_BIO_RESID
parameter_list|(
name|bp
parameter_list|)
value|(bp)->b_resid
end_define

begin_define
define|#
directive|define
name|MLX_BIO_DONE
parameter_list|(
name|bp
parameter_list|)
value|biodone(bp)
end_define

begin_define
define|#
directive|define
name|MLX_BIO_STATS_START
parameter_list|(
name|bp
parameter_list|)
value|devstat_start_transaction(&((struct mlxd_softc *)MLX_BIO_SOFTC(bp))->mlxd_stats)
end_define

begin_define
define|#
directive|define
name|MLX_BIO_STATS_END
parameter_list|(
name|bp
parameter_list|)
value|devstat_end_transaction_buf(&((struct mlxd_softc *)MLX_BIO_SOFTC(bp))->mlxd_stats, bp)
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|bio
name|mlx_bio
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bio_queue_head
name|mlx_bioq
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MLX_BIO_QINIT
parameter_list|(
name|bq
parameter_list|)
value|bioq_init(&bq);
end_define

begin_define
define|#
directive|define
name|MLX_BIO_QINSERT
parameter_list|(
name|bq
parameter_list|,
name|bp
parameter_list|)
value|bioq_insert_tail(&bq, bp)
end_define

begin_define
define|#
directive|define
name|MLX_BIO_QFIRST
parameter_list|(
name|bq
parameter_list|)
value|bioq_first(&bq)
end_define

begin_define
define|#
directive|define
name|MLX_BIO_QREMOVE
parameter_list|(
name|bq
parameter_list|,
name|bp
parameter_list|)
value|bioq_remove(&bq, bp)
end_define

begin_define
define|#
directive|define
name|MLX_BIO_IS_READ
parameter_list|(
name|bp
parameter_list|)
value|((bp)->bio_cmd == BIO_READ)
end_define

begin_define
define|#
directive|define
name|MLX_BIO_DATA
parameter_list|(
name|bp
parameter_list|)
value|(bp)->bio_data
end_define

begin_define
define|#
directive|define
name|MLX_BIO_LENGTH
parameter_list|(
name|bp
parameter_list|)
value|(bp)->bio_bcount
end_define

begin_define
define|#
directive|define
name|MLX_BIO_LBA
parameter_list|(
name|bp
parameter_list|)
value|(bp)->bio_pblkno
end_define

begin_define
define|#
directive|define
name|MLX_BIO_SOFTC
parameter_list|(
name|bp
parameter_list|)
value|(bp)->bio_dev->si_drv1
end_define

begin_define
define|#
directive|define
name|MLX_BIO_UNIT
parameter_list|(
name|bp
parameter_list|)
value|*(int *)((bp)->bio_dev->si_drv2)
end_define

begin_define
define|#
directive|define
name|MLX_BIO_SET_ERROR
parameter_list|(
name|bp
parameter_list|,
name|err
parameter_list|)
value|do { (bp)->bio_error = err; (bp)->bio_flags |= BIO_ERROR;} while(0)
end_define

begin_define
define|#
directive|define
name|MLX_BIO_HAS_ERROR
parameter_list|(
name|bp
parameter_list|)
value|((bp)->bio_flags& BIO_ERROR)
end_define

begin_define
define|#
directive|define
name|MLX_BIO_RESID
parameter_list|(
name|bp
parameter_list|)
value|(bp)->bio_resid
end_define

begin_define
define|#
directive|define
name|MLX_BIO_DONE
parameter_list|(
name|bp
parameter_list|)
value|biodone(bp)
end_define

begin_comment
comment|/* XXX nice to integrate bio_finish here */
end_comment

begin_define
define|#
directive|define
name|MLX_BIO_STATS_START
parameter_list|(
name|bp
parameter_list|)
value|devstat_start_transaction(&((struct mlxd_softc *)MLX_BIO_SOFTC(bp))->mlxd_stats)
end_define

begin_define
define|#
directive|define
name|MLX_BIO_STATS_END
parameter_list|(
name|bp
parameter_list|)
value|devstat_end_transaction_bio(&((struct mlxd_softc *)MLX_BIO_SOFTC(bp))->mlxd_stats, bp)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

