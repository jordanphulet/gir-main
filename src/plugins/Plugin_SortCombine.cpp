#include <GIRConfig.h>
#include <GIRLogger.h>
#include <plugins/Plugin_SortCombine.h>

extern "C" ReconPlugin* create( const char* alias )
{
	return new Plugin_SortCombine( "Plugin_SortCombine", alias );
}

extern "C" void destroy( ReconPlugin* plugin )
{
	delete plugin;
}

bool Plugin_SortCombine::Configure( GIRConfig& config, bool main_config, bool final_config )
{
	return true;
}

bool Plugin_SortCombine::Reconstruct( MRIData& mri_data )
{
	return true;
}

bool Plugin_SortCombine::Reconstruct( std::vector<MRIMeasurement>& meas_vector, MRIData& mri_data )
{
	// make sure mri_data is big enough, shouldn't have to do this...
	MRIDimensions max_dims = mri_data.Size();

	std::vector<MRIMeasurement>::iterator it;
	for( it = meas_vector.begin(); it != meas_vector.end(); it++ )
	{
		for( int i = 0; i < max_dims.GetNumDims(); i++ )
		{
			int this_dim = 0;
			it->index.GetDim( i, this_dim );
			int max_dim = 0;
			max_dims.GetDim( i, max_dim );

			max_dims.SetDim( i, max( max_dim, this_dim + 1 ) );
		}
	}
	GIRLogger::LogDebug( "### %s\n", max_dims.ToString().c_str() );
	mri_data = MRIData( max_dims, mri_data.IsComplex() );

	for( it = meas_vector.begin(); it != meas_vector.end(); it++ )
		if( !it->UnloadData( mri_data ) )
			GIRLogger::LogError( "Plugin_SortCombine::Reconstruct-> MRIMasurement::UnloadData failed, measurement was not added!\n" );
	return true;
}
