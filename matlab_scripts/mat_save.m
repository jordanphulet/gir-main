function [result] = mat_save( mri_data, params, meas_data )
	mytime = clock;
	save_tag = sprintf( '%d-%02d-%02d_%02d_%02d_%02d', mytime(1), mytime(2), mytime(3), mytime(4), mytime(5), round(mytime(6)) );
	save( sprintf( '%s/mat_save_%s.mat', getenv( 'HOME' ), save_tag ) );
	result = mri_data;
