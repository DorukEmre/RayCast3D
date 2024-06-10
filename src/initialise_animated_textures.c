#include "raycast3d.h"

void	initialise_animated_textures(t_data *data)
{
	data->anim1[0] = mlx_load_png("./texture/fish/fish_0.png");
	data->anim1[1] = mlx_load_png("./texture/fish/fish_1.png");
	if (!data->anim1[0] || !data->anim1[1])
		print_and_exit("Failed to initialise anim1 textures", 2, EXIT_FAILURE);

	data->anim2[0] = mlx_load_png("./texture/eyes/eyes_00.png");
	data->anim2[1] = mlx_load_png("./texture/eyes/eyes_01.png");
	data->anim2[2] = mlx_load_png("./texture/eyes/eyes_02.png");
	data->anim2[3] = mlx_load_png("./texture/eyes/eyes_03.png");
	data->anim2[4] = mlx_load_png("./texture/eyes/eyes_04.png");
	data->anim2[5] = mlx_load_png("./texture/eyes/eyes_05.png");
	data->anim2[6] = mlx_load_png("./texture/eyes/eyes_06.png");
	data->anim2[7] = mlx_load_png("./texture/eyes/eyes_07.png");
	data->anim2[8] = mlx_load_png("./texture/eyes/eyes_08.png");
	data->anim2[9] = mlx_load_png("./texture/eyes/eyes_09.png");
	data->anim2[10] = mlx_load_png("./texture/eyes/eyes_10.png");
	data->anim2[11] = mlx_load_png("./texture/eyes/eyes_11.png");
	data->anim2[12] = mlx_load_png("./texture/eyes/eyes_12.png");
	data->anim2[13] = mlx_load_png("./texture/eyes/eyes_13.png");
	data->anim2[14] = mlx_load_png("./texture/eyes/eyes_14.png");
	data->anim2[15] = mlx_load_png("./texture/eyes/eyes_15.png");
	data->anim2[16] = mlx_load_png("./texture/eyes/eyes_16.png");
	data->anim2[17] = mlx_load_png("./texture/eyes/eyes_17.png");
	data->anim2[18] = mlx_load_png("./texture/eyes/eyes_18.png");
	data->anim2[19] = mlx_load_png("./texture/eyes/eyes_19.png");
	data->anim2[20] = mlx_load_png("./texture/eyes/eyes_20.png");
	data->anim2[21] = mlx_load_png("./texture/eyes/eyes_21.png");
	data->anim2[22] = mlx_load_png("./texture/eyes/eyes_22.png");
	data->anim2[23] = mlx_load_png("./texture/eyes/eyes_23.png");
	data->anim2[24] = mlx_load_png("./texture/eyes/eyes_24.png");
	if (
    !data->anim2[0] || !data->anim2[1] || !data->anim2[2] || !data->anim2[3]
    || !data->anim2[4] || !data->anim2[5] || !data->anim2[6] || !data->anim2[7]
    || !data->anim2[8] || !data->anim2[9] || !data->anim2[10]
    || !data->anim2[11] || !data->anim2[12] || !data->anim2[13]
    || !data->anim2[14] || !data->anim2[15] || !data->anim2[16]
    || !data->anim2[17] || !data->anim2[18] || !data->anim2[19]
    || !data->anim2[20] || !data->anim2[21] || !data->anim2[22]
    || !data->anim2[23] || !data->anim2[24]
  )
		print_and_exit("Failed to initialise anim2 textures", 2, EXIT_FAILURE);

	data->anim3[0] = mlx_load_png("./texture/crab/crab_00.png");
	data->anim3[1] = mlx_load_png("./texture/crab/crab_01.png");
	data->anim3[2] = mlx_load_png("./texture/crab/crab_02.png");
	data->anim3[3] = mlx_load_png("./texture/crab/crab_03.png");
	data->anim3[4] = mlx_load_png("./texture/crab/crab_04.png");
	data->anim3[5] = mlx_load_png("./texture/crab/crab_05.png");
	data->anim3[6] = mlx_load_png("./texture/crab/crab_06.png");
	data->anim3[7] = mlx_load_png("./texture/crab/crab_07.png");
	data->anim3[8] = mlx_load_png("./texture/crab/crab_08.png");
	data->anim3[9] = mlx_load_png("./texture/crab/crab_09.png");
	data->anim3[10] = mlx_load_png("./texture/crab/crab_10.png");
	data->anim3[11] = mlx_load_png("./texture/crab/crab_11.png");
	data->anim3[12] = mlx_load_png("./texture/crab/crab_12.png");
	data->anim3[13] = mlx_load_png("./texture/crab/crab_13.png");
	data->anim3[14] = mlx_load_png("./texture/crab/crab_14.png");
	data->anim3[15] = mlx_load_png("./texture/crab/crab_15.png");
	data->anim3[16] = mlx_load_png("./texture/crab/crab_16.png");
	data->anim3[17] = mlx_load_png("./texture/crab/crab_17.png");
	data->anim3[18] = mlx_load_png("./texture/crab/crab_18.png");
	data->anim3[19] = mlx_load_png("./texture/crab/crab_19.png");
	data->anim3[20] = mlx_load_png("./texture/crab/crab_20.png");
	data->anim3[21] = mlx_load_png("./texture/crab/crab_21.png");
	data->anim3[22] = mlx_load_png("./texture/crab/crab_22.png");
	data->anim3[23] = mlx_load_png("./texture/crab/crab_23.png");
	if (
    !data->anim3[0] || !data->anim3[1] || !data->anim3[2] || !data->anim3[3]
    || !data->anim3[4] || !data->anim3[5] || !data->anim3[6] || !data->anim3[7]
    || !data->anim3[8] || !data->anim3[9] || !data->anim3[10]
    || !data->anim3[11] || !data->anim3[12] || !data->anim3[13]
    || !data->anim3[14] || !data->anim3[15] || !data->anim3[16]
    || !data->anim3[17] || !data->anim3[18] || !data->anim3[19]
    || !data->anim3[20] || !data->anim3[21] || !data->anim3[22]
    || !data->anim3[23]
  )
		print_and_exit("Failed to initialise anim3 textures", 2, EXIT_FAILURE);

	data->anim4[0] = mlx_load_png("./texture/dolphin/dolphin_00.png");
	data->anim4[1] = mlx_load_png("./texture/dolphin/dolphin_01.png");
	data->anim4[2] = mlx_load_png("./texture/dolphin/dolphin_02.png");
	data->anim4[3] = mlx_load_png("./texture/dolphin/dolphin_03.png");
	data->anim4[4] = mlx_load_png("./texture/dolphin/dolphin_04.png");
	data->anim4[5] = mlx_load_png("./texture/dolphin/dolphin_05.png");
	data->anim4[6] = mlx_load_png("./texture/dolphin/dolphin_06.png");
	data->anim4[7] = mlx_load_png("./texture/dolphin/dolphin_07.png");
	data->anim4[8] = mlx_load_png("./texture/dolphin/dolphin_08.png");
	data->anim4[9] = mlx_load_png("./texture/dolphin/dolphin_09.png");
	if (
    !data->anim4[0] || !data->anim4[1] || !data->anim4[2] || !data->anim4[3]
    || !data->anim4[4] || !data->anim4[5] || !data->anim4[6] || !data->anim4[7]
    || !data->anim4[8] || !data->anim4[9]
  )
		print_and_exit("Failed to initialise anim4 textures", 2, EXIT_FAILURE);

  data->door_closed[0] = mlx_load_png("./texture/open_sign/open_sign_00.png");
	data->door_closed[1] = mlx_load_png("./texture/open_sign/open_sign_01.png");
	data->door_closed[2] = mlx_load_png("./texture/open_sign/open_sign_02.png");
	data->door_closed[3] = mlx_load_png("./texture/open_sign/open_sign_03.png");
	data->door_closed[4] = mlx_load_png("./texture/open_sign/open_sign_04.png");
	data->door_closed[5] = mlx_load_png("./texture/open_sign/open_sign_05.png");
	data->door_closed[6] = mlx_load_png("./texture/open_sign/open_sign_06.png");
	data->door_closed[7] = mlx_load_png("./texture/open_sign/open_sign_07.png");
	data->door_closed[8] = mlx_load_png("./texture/open_sign/open_sign_08.png");
	data->door_closed[9] = mlx_load_png("./texture/open_sign/open_sign_09.png");
	data->door_closed[10] = mlx_load_png("./texture/open_sign/open_sign_10.png");
	data->door_closed[11] = mlx_load_png("./texture/open_sign/open_sign_11.png");
	data->door_closed[12] = mlx_load_png("./texture/open_sign/open_sign_12.png");
	data->door_closed[13] = mlx_load_png("./texture/open_sign/open_sign_13.png");
	data->door_closed[14] = mlx_load_png("./texture/open_sign/open_sign_14.png");
	data->door_closed[15] = mlx_load_png("./texture/open_sign/open_sign_15.png");
	data->door_closed[16] = mlx_load_png("./texture/open_sign/open_sign_16.png");
	data->door_closed[17] = mlx_load_png("./texture/open_sign/open_sign_17.png");
	if (
    !data->door_closed[0] || !data->door_closed[1] || !data->door_closed[2]
    || !data->door_closed[3] || !data->door_closed[4] || !data->door_closed[5]
    || !data->door_closed[6] || !data->door_closed[7] || !data->door_closed[8]
    || !data->door_closed[9] || !data->door_closed[10] || !data->door_closed[11]
    || !data->door_closed[12] || !data->door_closed[13]
    || !data->door_closed[14] || !data->door_closed[15]
    || !data->door_closed[16] || !data->door_closed[17]
  )
		print_and_exit("Failed to initialise door textures", 2, EXIT_FAILURE);
}
