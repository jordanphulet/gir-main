function [result] = mat_save( mri_data, params, meas_data )
	mytime = clock;
	save_tag = sprintf( '%d-%02d-%02d_%02d_%02d_%02d', mytime(1), mytime(2), mytime(3), mytime(4), mytime(5), round(mytime(6)) );

	if( isfield( params, 'save_dir' ) )
		save_path = sprintf( '%s/mat_save_%s.mat', params.save_dir, save_tag );
	else
		save_path = sprintf( '%s/export/mat_save_%s.mat', getenv( 'GIR_DIR' ), save_tag );
	end
	save_path
	save( save_path );
	result = mri_data;
