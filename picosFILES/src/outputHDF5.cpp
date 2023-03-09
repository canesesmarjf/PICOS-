#include "outputHDF5.h"

// Function to save a single integer value
void HDF_TYP::saveToHDF5(H5File * file, string name, int * value)
{
	H5std_string nameSpace( name );
	int data[1] = {*value};
	hsize_t dims[1] = {1};
	DataSpace * dataspace = new DataSpace(1, dims);
	DataSet * dataset = new DataSet(file->createDataSet( nameSpace, PredType::NATIVE_INT, *dataspace ));

	dataset->write( data, PredType::NATIVE_INT);

	delete dataspace;
	delete dataset;
}


// Function to save a single CPP_TYPE value
void HDF_TYP::saveToHDF5(H5File * file, string name, CPP_TYPE * value)
{
	H5std_string nameSpace( name );
	CPP_TYPE data[1] = {*value};
	hsize_t dims[1] = {1};
	DataSpace * dataspace = new DataSpace(1, dims);
	DataSet * dataset = new DataSet(file->createDataSet( nameSpace, HDF_TYPE, *dataspace ));

	dataset->write( data, HDF_TYPE);

	delete dataspace;
	delete dataset;
}


// Function to save a single integer value (to a HDF5 group)
void HDF_TYP::saveToHDF5(Group * group, string name, int * value)
{
	H5std_string nameSpace( name );
	int data[1] = {*value};
	hsize_t dims[1] = {1};
	DataSpace * dataspace = new DataSpace(1, dims);
	DataSet * dataset = new DataSet(group->createDataSet( nameSpace, PredType::NATIVE_INT, *dataspace ));

	dataset->write( data, PredType::NATIVE_INT);

	delete dataspace;
	delete dataset;
}


// Function to save a single CPP_TYPE value (to a HDF5 group)
void HDF_TYP::saveToHDF5(Group * group, string name, CPP_TYPE * value)
{
	H5std_string nameSpace( name );
	CPP_TYPE data[1] = {*value};
	hsize_t dims[1] = {1};
	DataSpace * dataspace = new DataSpace(1, dims);
	DataSet * dataset = new DataSet(group->createDataSet( nameSpace, HDF_TYPE, *dataspace ));

	dataset->write( data, HDF_TYPE);

	delete dataspace;
	delete dataset;
}


// Function to save a vector of int values
void HDF_TYP::saveToHDF5(H5File * file, string name, std::vector<int> * values)
{
	H5std_string nameSpace( name );
	unsigned long long int size = (unsigned long long int)values->size();

	int * data;
   	data = new int[size];
        std::copy(values->begin(), values->end(), data);

	hsize_t dims[1] = {size};
	DataSpace * dataspace = new DataSpace(1, dims);
	DataSet * dataset = new DataSet(file->createDataSet( nameSpace, PredType::NATIVE_INT, *dataspace ));

	dataset->write( data, PredType::NATIVE_INT);

	delete dataspace;
	delete dataset;
}


// Function to save a vector of CPP_TYPE values
void HDF_TYP::saveToHDF5(H5File * file, string name, std::vector<CPP_TYPE> * values)
{
	H5std_string nameSpace( name );
	unsigned long long int size = (unsigned long long int)values->size();

	CPP_TYPE * data;
   	data = new CPP_TYPE[size];
    std::copy(values->begin(), values->end(), data);

	hsize_t dims[1] = {size};
	DataSpace * dataspace = new DataSpace(1, dims);
	DataSet * dataset = new DataSet(file->createDataSet( nameSpace, HDF_TYPE, *dataspace ));

	dataset->write( data, HDF_TYPE);

	delete dataspace;
	delete dataset;
}


// Function to save an Armadillo ivec vector (to a HDF5 file)
void HDF_TYP::saveToHDF5(H5File * file, string name, arma::ivec * values)
{
	H5std_string nameSpace( name );

	hsize_t dims[1] = {(hsize_t)values->n_elem};
	DataSpace * dataspace = new DataSpace(1, dims);
	DataSet * dataset = new DataSet(file->createDataSet( nameSpace, PredType::NATIVE_INT, *dataspace ));

	dataset->write( values->memptr(), PredType::NATIVE_INT);

	delete dataspace;
	delete dataset;
}


// Function to save an Armadillo ivec vector (to a HDF5 group)
void HDF_TYP::saveToHDF5(Group * group, string name, arma::ivec * values)
{
	H5std_string nameSpace( name );

	hsize_t dims[1] = {(hsize_t)values->n_elem};
	DataSpace * dataspace = new DataSpace(1, dims);
	DataSet * dataset = new DataSet(group->createDataSet( nameSpace, PredType::NATIVE_INT, *dataspace ));

	dataset->write( values->memptr(), PredType::NATIVE_INT);

	delete dataspace;
	delete dataset;
}


// Function to save an Armadillo vec vector
void HDF_TYP::saveToHDF5(H5File * file, string name, arma::vec * values)
{
	H5std_string nameSpace( name );

	hsize_t dims[1] = {(hsize_t)values->n_elem};
	DataSpace * dataspace = new DataSpace(1, dims);
	DataSet * dataset = new DataSet(file->createDataSet( nameSpace, HDF_TYPE, *dataspace ));

	dataset->write( values->memptr(), HDF_TYPE);

	delete dataspace;
	delete dataset;
}


// Function to save an Armadillo vec vector (to a HDF5 group)
void HDF_TYP::saveToHDF5(Group * group, string name, arma::vec * values)
{
	H5std_string nameSpace( name );

	hsize_t dims[1] = {(hsize_t)values->n_elem};
	DataSpace * dataspace = new DataSpace(1, dims);
	DataSet * dataset = new DataSet(group->createDataSet( nameSpace, HDF_TYPE, *dataspace ));

	dataset->write( values->memptr(), HDF_TYPE);

	delete dataspace;
	delete dataset;
}


// Function to save an Armadillo fvec vector (to a HDF5 group)
void HDF_TYP::saveToHDF5(Group * group, string name, arma::fvec * values)
{
	H5std_string nameSpace( name );

	hsize_t dims[1] = {(hsize_t)values->n_elem};
	DataSpace * dataspace = new DataSpace(1, dims);
	DataSet * dataset = new DataSet(group->createDataSet( nameSpace, HDF_TYPE, *dataspace ));

	dataset->write( values->memptr(), HDF_TYPE);

	delete dataspace;
	delete dataset;
}


// Function to save an Armadillo imat vector (to a HDF5 file)
void HDF_TYP::saveToHDF5(H5File * file, string name, arma::imat * values)
{
	H5std_string nameSpace( name );

	hsize_t dims[2] = {(hsize_t)values->n_cols, (hsize_t)values->n_rows};
	DataSpace * dataspace = new DataSpace(2, dims);
	DataSet * dataset = new DataSet(file->createDataSet( nameSpace, PredType::NATIVE_INT, *dataspace ));

	dataset->write( values->memptr(), PredType::NATIVE_INT);

	delete dataspace;
	delete dataset;
}


// Function to save an Armadillo imat vector (to a HDF5 group)
void HDF_TYP::saveToHDF5(Group * group, string name, arma::imat * values)
{
	H5std_string nameSpace( name );

	hsize_t dims[2] = {(hsize_t)values->n_cols, (hsize_t)values->n_rows};
	DataSpace * dataspace = new DataSpace(2, dims);
	DataSet * dataset = new DataSet(group->createDataSet( nameSpace, PredType::NATIVE_INT, *dataspace ));

	dataset->write( values->memptr(), PredType::NATIVE_INT);

	delete dataspace;
	delete dataset;
}


// Function to save an Armadillo vec vector (to a HDF5 group)
void HDF_TYP::saveToHDF5(Group * group, string name, arma::mat * values)
{
	H5std_string nameSpace( name );

	hsize_t dims[2] = {(hsize_t)values->n_cols, (hsize_t)values->n_rows};
	DataSpace * dataspace = new DataSpace(2, dims);
	DataSet * dataset = new DataSet(group->createDataSet( nameSpace, HDF_TYPE, *dataspace ));

	dataset->write( values->memptr(), HDF_TYPE);

	delete dataspace;
	delete dataset;
}


// Function to save an Armadillo vec vector (to a HDF5 group)
void HDF_TYP::saveToHDF5(Group * group, string name, arma::fmat * values)
{
	H5std_string nameSpace( name );

	hsize_t dims[2] = {(hsize_t)values->n_cols, (hsize_t)values->n_rows};
	DataSpace * dataspace = new DataSpace(2, dims);
	DataSet * dataset = new DataSet(group->createDataSet( nameSpace, HDF_TYPE, *dataspace ));

	dataset->write( values->memptr(), HDF_TYPE);

	delete dataspace;
	delete dataset;
}


// Constructor:
// =============================================================================
HDF_TYP::HDF_TYP(params_TYP * params, mesh_TYP * mesh, vector<ions_TYP> * IONS)
{
  if (params->mpi.MPI_DOMAIN_NUMBER == 0)
  {
    try
    {
      string name;
      string path;

      int int_value;
      CPP_TYPE cpp_type_value;
      std::vector<CPP_TYPE> vector_values;

      arma::vec vec_values;
      arma::fvec fvec_values;

      path = params->PATH + "/HDF5/";
      name = path + "main.h5";
      const H5std_string	FILE_NAME( name );
      name.clear();

      Exception::dontPrint();

      // Create a new file using the default property lists.
      H5File * outputFile = new H5File( FILE_NAME, H5F_ACC_TRUNC );

			// Root group data:
			{
      name = "smoothingParameter";
      cpp_type_value = params->smoothingParameter;
      saveToHDF5(outputFile, name, &cpp_type_value);
      name.clear();

      name = "filtersPerIterationFields";
      saveToHDF5(outputFile, name, &params->filtersPerIterationFields);
      name.clear();

      name = "numOfMPIs";
      saveToHDF5(outputFile, name, &params->mpi.NUMBER_MPI_DOMAINS);
      name.clear();

      name = "numMPIsParticles";
      saveToHDF5(outputFile, name, &params->mpi.MPIS_PARTICLES);
      name.clear();

      name = "numMPIsFields";
      saveToHDF5(outputFile, name, &params->mpi.MPIS_FIELDS);
      name.clear();
			}

      // Fundamental scales group
			/*
      Group * group_scales = new Group( outputFile->createGroup( "/scales" ) );

      name = "electronSkinDepth";
      cpp_type_value = FS->electronSkinDepth;
      saveToHDF5(group_scales, name, &cpp_type_value);
      name.clear();

      name = "electronGyroPeriod";
      cpp_type_value = FS->electronGyroPeriod;
      saveToHDF5(group_scales, name, &cpp_type_value);
      name.clear();

      name = "electronGyroRadius";
      cpp_type_value = FS->electronGyroRadius;
      saveToHDF5(group_scales, name, &cpp_type_value);
      name.clear();

      name = "ionGyroRadius";
      #ifdef HDF5_DOUBLE
      vec_values = zeros(params->numberOfParticleSpecies);
      for (int ss=0; ss<params->numberOfParticleSpecies; ss++)
              vec_values(ss) = FS->ionGyroRadius[ss];
      saveToHDF5(group_scales, name, &vec_values);
      #elif defined HDF5_FLOAT
      fvec_values = zeros<fvec>(params->numberOfParticleSpecies);
      for (int ss=0; ss<params->numberOfParticleSpecies; ss++)
              fvec_values(ss) = (float)FS->ionGyroRadius[ss];
      saveToHDF5(group_scales, name, &fvec_values);
      #endif
      name.clear();

      name = "ionGyroPeriod";
      #ifdef HDF5_DOUBLE
      vec_values = zeros(params->numberOfParticleSpecies);
      for (int ss=0; ss<params->numberOfParticleSpecies; ss++)
              vec_values(ss) = FS->ionGyroPeriod[ss];
      saveToHDF5(group_scales, name, &vec_values);
      #elif defined HDF5_FLOAT
      fvec_values = zeros<fvec>(params->numberOfParticleSpecies);
      for (int ss=0; ss<params->numberOfParticleSpecies; ss++)
              fvec_values(ss) = (float)FS->ionGyroPeriod[ss];
      saveToHDF5(group_scales, name, &fvec_values);
      #endif
      name.clear();

      name = "ionSkinDepth";
      #ifdef HDF5_DOUBLE
      vec_values = zeros(params->numberOfParticleSpecies);
      for (int ss=0; ss<params->numberOfParticleSpecies; ss++)
              vec_values(ss) = FS->ionSkinDepth[ss];
      saveToHDF5(group_scales, name, &vec_values);
      #elif defined HDF5_FLOAT
      fvec_values = zeros<fvec>(params->numberOfParticleSpecies);
      for (int ss=0; ss<params->numberOfParticleSpecies; ss++)
              fvec_values(ss) = (float)FS->ionSkinDepth[ss];
      saveToHDF5(group_scales, name, &fvec_values);
      #endif
      name.clear();

      delete group_scales;
*/

      //Geometry of the mesh
			{
      Group * group_mesh = new Group( outputFile->createGroup( "/mesh" ) );

			name = "A0";
      cpp_type_value = params->mesh_params.A0;
      saveToHDF5(group_mesh, name, &cpp_type_value);
      name.clear();

			name = "B0";
      cpp_type_value = params->mesh_params.B0;
      saveToHDF5(group_mesh, name, &cpp_type_value);
      name.clear();

			name = "r0_min";
			cpp_type_value = params->mesh_params.r0_min;
			saveToHDF5(group_mesh, name, &cpp_type_value);
			name.clear();

			name = "r0_max";
			cpp_type_value = params->mesh_params.r0_max;
			saveToHDF5(group_mesh, name, &cpp_type_value);
			name.clear();

      name = "dx";
      cpp_type_value = params->mesh_params.dx;
      saveToHDF5(group_mesh, name, &cpp_type_value);
      name.clear();

			name = "ionSkinDepth";
      cpp_type_value = params->mesh_params.ionSkinDepth;
      saveToHDF5(group_mesh, name, &cpp_type_value);
      name.clear();

      name = "Lx_min";
      cpp_type_value = params->mesh_params.Lx_min;
      saveToHDF5(group_mesh, name, &cpp_type_value);
      name.clear();

			name = "Lx_max";
			cpp_type_value = params->mesh_params.Lx_max;
			saveToHDF5(group_mesh, name, &cpp_type_value);
			name.clear();

      name = "Nx_PER_MPI";
      int_value = params->mesh_params.Nx_PER_MPI;
      saveToHDF5(group_mesh, name, &int_value);
      name.clear();

      name = "Nx_IN_SIM";
      int_value = params->mesh_params.Nx;
      saveToHDF5(group_mesh, name, &int_value);
      name.clear();

      // name = "X_MPI_CART_COORD";
      // int_value = params->mpi.MPI_CART_COORDS_1D[0];
      // saveToHDF5(group_mesh, name, &int_value);
      // name.clear();

      name = "x_m";
      #ifdef HDF5_DOUBLE
      vec_values = mesh->xm;
      saveToHDF5(group_mesh, name, &vec_values);
      #elif defined HDF5_FLOAT
      fvec_values = conv_to<fvec>::from(mesh->xm);
      saveToHDF5(group_mesh, name, &fvec_values);
      #endif

      name.clear();

      delete group_mesh;
			}

      //Ions
			{
      Group * group_ions = new Group( outputFile->createGroup( "/ions" ) );

      name = "numberOfParticleSpecies";
      int_value = params->numberOfParticleSpecies;
      saveToHDF5(group_ions, name, &int_value);
      name.clear();

      for(int ii=0;ii<params->numberOfParticleSpecies;ii++)
      {
        stringstream ionSpec;
        ionSpec << (ii+1);
        name = "/ions/species_" + ionSpec.str();
        Group * group_ionSpecies = new Group( outputFile->createGroup( name ) );
        name.clear();

				name = "speciesType";
				cpp_type_value = (CPP_TYPE)IONS->at(ii).SPECIES;
				saveToHDF5(group_ionSpecies, name, &cpp_type_value);
				name.clear();

        name = "N_CP_IN_SIM";
        cpp_type_value = (CPP_TYPE)IONS->at(ii).N_CP_IN_SIM;
        saveToHDF5(group_ionSpecies, name, &cpp_type_value);
        name.clear();

        name = "N_CP_MPI";
        cpp_type_value = (CPP_TYPE)IONS->at(ii).N_CP_MPI;
        saveToHDF5(group_ionSpecies, name, &cpp_type_value);
        name.clear();

        name = "N_CP_MPI_Output";
        cpp_type_value = (CPP_TYPE)IONS->at(ii).N_CP_MPI_Output;
        saveToHDF5(group_ionSpecies, name, &cpp_type_value);
        name.clear();

				name = "pct_N_CP_MPI_Output";
				cpp_type_value = (CPP_TYPE)IONS->at(ii).pct_N_CP_MPI_Output;
				saveToHDF5(group_ionSpecies, name, &cpp_type_value);
				name.clear();

        name = "K";
        cpp_type_value = (CPP_TYPE)IONS->at(ii).K;
        saveToHDF5(group_ionSpecies, name, &cpp_type_value);
        name.clear();

        name = "M";
        cpp_type_value = (CPP_TYPE)IONS->at(ii).M;
        saveToHDF5(group_ionSpecies, name, &cpp_type_value);
        name.clear();

        name = "Q";
        cpp_type_value = (CPP_TYPE)IONS->at(ii).Q;
        saveToHDF5(group_ionSpecies, name, &cpp_type_value);
        name.clear();

        name = "Z";
        cpp_type_value = (CPP_TYPE)IONS->at(ii).Z;
        saveToHDF5(group_ionSpecies, name, &cpp_type_value);
        name.clear();

        delete group_ionSpecies;
      }

      delete group_ions;
			}

			/*
			//electrons
			{
      Group * group_ions = new Group( outputFile->createGroup( "/electrons" ) );

      name = "numberOfParticleSpecies";
      int_value = params->numberOfParticleSpecies;
      saveToHDF5(group_ions, name, &int_value);
      name.clear();

      for(int ii=0;ii<params->numberOfParticleSpecies;ii++)
      {
        stringstream ionSpec;
        ionSpec << (ii+1);
        name = "/ions/species_" + ionSpec.str();
        Group * group_ionSpecies = new Group( outputFile->createGroup( name ) );
        name.clear();

				name = "speciesType";
				cpp_type_value = (CPP_TYPE)IONS->at(ii).SPECIES;
				saveToHDF5(group_ionSpecies, name, &cpp_type_value);
				name.clear();

        name = "N_CP_IN_SIM";
        cpp_type_value = (CPP_TYPE)IONS->at(ii).N_CP_IN_SIM;
        saveToHDF5(group_ionSpecies, name, &cpp_type_value);
        name.clear();

        name = "N_CP_MPI";
        cpp_type_value = (CPP_TYPE)IONS->at(ii).N_CP_MPI;
        saveToHDF5(group_ionSpecies, name, &cpp_type_value);
        name.clear();

        name = "N_CP_MPI_Output";
        cpp_type_value = (CPP_TYPE)IONS->at(ii).N_CP_MPI_Output;
        saveToHDF5(group_ionSpecies, name, &cpp_type_value);
        name.clear();

        name = "K";
        cpp_type_value = (CPP_TYPE)IONS->at(ii).K;
        saveToHDF5(group_ionSpecies, name, &cpp_type_value);
        name.clear();

        name = "M";
        cpp_type_value = (CPP_TYPE)IONS->at(ii).M;
        saveToHDF5(group_ionSpecies, name, &cpp_type_value);
        name.clear();

        name = "Q";
        cpp_type_value = (CPP_TYPE)IONS->at(ii).Q;
        saveToHDF5(group_ionSpecies, name, &cpp_type_value);
        name.clear();

        name = "Z";
        cpp_type_value = (CPP_TYPE)IONS->at(ii).Z;
        saveToHDF5(group_ionSpecies, name, &cpp_type_value);
        name.clear();

        delete group_ionSpecies;
      }

      delete group_ions;
			}
			*/

      delete outputFile;

    }//End of try block

    // catch failure caused by the H5File operations:
    // =============================================
    catch( FileIException error )
    {
          	error.printErrorStack();
    }

    // catch failure caused by the DataSet operations:
    // ===============================================
    catch( DataSetIException error )
    {
          	error.printErrorStack();
    }

    // catch failure caused by the DataSpace operations:
    // ================================================
    catch( DataSpaceIException error )
    {
          	error.printErrorStack();
    }
  } // MPI-0
}


void HDF_TYP::saveOutputs(const params_TYP * params, const vector<ions_TYP> * IONS, electrons_TYP * electrons, fields_TYP * fields, const CS_TYP * CS, const int it, double totalTime)
{
	try
	{
		stringstream iteration;
		stringstream dn;

		string name, path;
		path = params->PATH + "/HDF5/";

		dn << params->mpi.COMM_RANK;

		H5std_string FILE_NAME;

		// Save particles data
		if (params->mpi.COMM_COLOR == PARTICLES_MPI_COLOR)
		{
			name = path + "PARTICLES_FILE_" + dn.str() + ".h5";
		}
		else if (params->mpi.COMM_COLOR == FIELDS_MPI_COLOR)
		{
			name = path + "FIELDS_FILE_" + dn.str() + ".h5";
		}

		FILE_NAME = name;

		name.clear();

		H5File * outputFile;

		if(it == 0)
		{
			outputFile = new H5File( FILE_NAME, H5F_ACC_TRUNC );// Create a new file using the default property lists.
		}
		else
		{
			outputFile = new H5File( FILE_NAME, H5F_ACC_RDWR );// Create a new file using the default property lists.
		}

		iteration << it;

		string group_iteration_name;
		group_iteration_name = "/" + iteration.str();
		Group * group_iteration = new Group( outputFile->createGroup( group_iteration_name ) );

		CPP_TYPE cpp_type_value;

		name = "time";
		cpp_type_value = (CPP_TYPE)totalTime;
		saveToHDF5(group_iteration, name, &cpp_type_value);
		name.clear();

		// Save particles data
		if (params->mpi.COMM_COLOR == PARTICLES_MPI_COLOR)
		{
			saveIonsVariables(params, IONS, electrons, CS, group_iteration);
		}
		else if (params->mpi.COMM_COLOR == FIELDS_MPI_COLOR)
		{
			saveFieldsVariables(params, fields, CS, group_iteration);
		}

		delete group_iteration;

		delete outputFile;
	}//End of try block

	// catch failure caused by the H5File operations
  catch( FileIException error )
	{
		error.printErrorStack();
  }

	// catch failure caused by the DataSet operations
  catch( DataSetIException error )
	{
		error.printErrorStack();
  }

	// catch failure caused by the DataSpace operations
  catch( DataSpaceIException error )
	{
		error.printErrorStack();
  }
}


void HDF_TYP::saveIonsVariables(const params_TYP * params, const vector<ions_TYP> * IONS, electrons_TYP * electrons, const CS_TYP * CS, const Group * group_iteration)
{
	unsigned int iIndex(params->mesh_params.Nx_PER_MPI*params->mpi.MPI_DOMAIN_NUMBER_CART+1);
	unsigned int fIndex(params->mesh_params.Nx_PER_MPI*(params->mpi.MPI_DOMAIN_NUMBER_CART+1));

	try
	{
		string name;

		int int_value;
		CPP_TYPE cpp_type_value;
		std::vector<CPP_TYPE> vector_values;

		arma::ivec ivec_values;

		arma::vec vec_values;
		arma::fvec fvec_values;

		arma::mat mat_values;
		arma::fmat fmat_values;

		// Ions:
		{
			name = "ions";
			Group * group_ions = new Group( group_iteration->createGroup( "ions" ) );
			name.clear();

			//Iterations over the ion species.
			for(int ii=0; ii<IONS->size(); ii++)
			{
				// Determine total number of particles to record:
				unsigned int N = IONS->at(ii).N_CP_MPI_Output;

				stringstream ionSpec;
				ionSpec << (ii+1);
				name = "species_" + ionSpec.str();
				Group * group_ionSpecies = new Group( group_ions->createGroup( name ) );
				name.clear();

				// Loop over all output variables:
				for(int ov=0; ov<params->outputs_variables.size(); ov++)
				{
					if(params->outputs_variables.at(ov) == "x_p")
					{
						// Particle position:
						name = "x_p";

						#ifdef HDF5_DOUBLE
						vec_values = CS->length*IONS->at(ii).x_p.subvec(0,N-1);
						saveToHDF5(group_ionSpecies, name, &vec_values);
						#elif defined HDF5_FLOAT
						fvec_values = conv_to<fvec>::from(CS->length*IONS->at(ii).x_p.subvec(0,N-1));
						saveToHDF5(group_ionSpecies, name, &fvec_values);
						#endif
						name.clear();

					 }
					if(params->outputs_variables.at(ov) == "v_p")
					{
						// Velocity vector:
						name = "v_p";

						#ifdef HDF5_DOUBLE
						mat_values = CS->velocity*IONS->at(ii).v_p.submat(0,0,N-1,1);
						saveToHDF5(group_ionSpecies, name, &mat_values);
						#elif defined HDF5_FLOAT
						fmat_values = conv_to<fmat>::from(CS->velocity*IONS->at(ii).v_p.submat(0,0,N-1,1));
						saveToHDF5(group_ionSpecies, name, &fmat_values);
						#endif
						name.clear();
					}
					if(params->outputs_variables.at(ov) == "mu_p")
					{
						// Particle magnetic moment
						name = "mu_p";

						#ifdef HDF5_DOUBLE
						vec_values = IONS->at(ii).mu_p.subvec(0,N-1)*CS->magneticMoment;
						saveToHDF5(group_ionSpecies, name, &vec_values);
						#elif defined HDF5_FLOAT
						fvec_values = conv_to<fvec>::from(IONS->at(ii).mu_p.subvec(0,N-1)*CS->magneticMoment);
						saveToHDF5(group_ionSpecies, name, &fvec_values);
						#endif
						name.clear();
					 }
					if(params->outputs_variables.at(ov) == "a_p")
					{
						//Particle weight
						name = "a_p";

						#ifdef HDF5_DOUBLE
						vec_values = IONS->at(ii).a_p.subvec(0,N-1);
						saveToHDF5(group_ionSpecies, name, &vec_values);
						#elif defined HDF5_FLOAT
						fvec_values = conv_to<fvec>::from(IONS->at(ii).a_p.subvec(0,N-1));
						saveToHDF5(group_ionSpecies, name, &fvec_values);
						#endif
						name.clear();
					}
					if(params->outputs_variables.at(ov) == "Ex_p")
					{
						// Particle-defined electric field:
						name = "Ex_p";

						#ifdef HDF5_DOUBLE
						vec_values = CS->eField*IONS->at(ii).Ex_p.subvec(0,N-1);
						saveToHDF5(group_ionSpecies, name, &vec_values);
						#elif defined HDF5_FLOAT
						fvec_values = conv_to<fvec>::from( CS->eField*IONS->at(ii).Ex_p.subvec(0,N-1));
						saveToHDF5(group_ionSpecies, name, &fvec_values);
						#endif
						name.clear();
					}
					if(params->outputs_variables.at(ov) == "Bx_p")
					{
						// Particle-defined magnetic field:
						name = "Bx_p";

						#ifdef HDF5_DOUBLE
						vec_values = CS->bField*IONS->at(ii).Bx_p.subvec(0,N-1);
						saveToHDF5(group_ionSpecies, name, &vec_values);
						#elif defined HDF5_FLOAT
						fvec_values = conv_to<fvec>::from( CS->bField*IONS->at(ii).Bx_p.subvec(0,N-1));
						saveToHDF5(group_ionSpecies, name, &fvec_values);
						#endif
						name.clear();
					}
					if(params->outputs_variables.at(ov) == "n_p")
					{
						// Particle-defined ion density:
						name = "n_p";

						#ifdef HDF5_DOUBLE
						vec_values = IONS->at(ii).n_p.subvec(0,N-1)/CS->volume;
						saveToHDF5(group_ionSpecies, name, &vec_values);
						#elif defined HDF5_FLOAT
						fvec_values = conv_to<fvec>::from(IONS->at(ii).n_p.subvec(0,N-1))/CS->volume;
						saveToHDF5(group_ionSpecies, name, &fvec_values);
						#endif
						name.clear();
					 }
					if(params->outputs_variables.at(ov) == "nv_p")
					{
						 // Particle-defined ion flux:
						 name = "nv_p";

						 #ifdef HDF5_DOUBLE
						 vec_values = IONS->at(ii).nv_p.subvec(0,N-1)*CS->velocity/CS->volume;
						 saveToHDF5(group_ionSpecies, name, &vec_values);
						 #elif defined HDF5_FLOAT
						 fvec_values = conv_to<fvec>::from(IONS->at(ii).nv_p.subvec(0,N-1))*CS->velocity/CS->volume;
						 saveToHDF5(group_ionSpecies, name, &fvec_values);
						 #endif
						 name.clear();
					}
					if(params->outputs_variables.at(ov) == "Tpar_p")
					{
						// Particle-defined parallel ion temperature:
						name = "Tpar_p";

						#ifdef HDF5_DOUBLE
						vec_values = IONS->at(ii).Tpar_p.subvec(0,N-1)*CS->temperature*F_KB/F_E;
						saveToHDF5(group_ionSpecies, name, &vec_values);
						#elif defined HDF5_FLOAT
						fvec_values = conv_to<fvec>::from(IONS->at(ii).Tpar_p.subvec(0,N-1))*CS->temperature*F_KB/F_E;
						saveToHDF5(group_ionSpecies, name, &fvec_values);
						#endif
						name.clear();
					}
					if(params->outputs_variables.at(ov) == "Tper_p")
					{
						//PAticle-defined perp ion temperature:
						name = "Tper_p";

						#ifdef HDF5_DOUBLE
						vec_values = IONS->at(ii).Tper_p.subvec(0,N-1)*CS->temperature*F_KB/F_E;
						saveToHDF5(group_ionSpecies, name, &vec_values);
						#elif defined HDF5_FLOAT
						fvec_values = conv_to<fvec>::from(IONS->at(ii).Tper_p.subvec(0,N-1))*CS->temperature*F_KB/F_E;
						saveToHDF5(group_ionSpecies, name, &fvec_values);
						#endif
						name.clear();
					}
					if(params->outputs_variables.at(ov) == "Te_p")
					{
						// Particle-defined electron temperature:
						name = "Te_p";

						#ifdef HDF5_DOUBLE
						vec_values = IONS->at(ii).Te_p.subvec(0,N-1)*CS->temperature*F_KB/F_E; // [eV]
						saveToHDF5(group_ionSpecies, name, &vec_values);
						#elif defined HDF5_FLOAT
						fvec_values = conv_to<fvec>::from(IONS->at(ii).Te_p.subvec(0,N-1))*CS->temperature*F_KB/F_E; // [eV]
						saveToHDF5(group_ionSpecies, name, &fvec_values);
						#endif
						name.clear();
					}
					if(params->outputs_variables.at(ov) == "n_m")
					{
						if (params->mpi.IS_PARTICLES_ROOT)
						{
							//Saving ions species density
							name = "n_m";
							#ifdef HDF5_DOUBLE
							vec_values = IONS->at(ii).n_m.subvec(1,params->mesh_params.Nx)/CS->volume;
							saveToHDF5(group_ionSpecies, name, &vec_values);
							#elif defined HDF5_FLOAT
							fvec_values = conv_to<fvec>::from(IONS->at(ii).n_m.subvec(1,params->mesh_params.Nx)/CS->volume);
							saveToHDF5(group_ionSpecies, name, &fvec_values);
							#endif
							name.clear();

							//Saving ions computational particle density
							name = "ncp_m";
							#ifdef HDF5_DOUBLE
							vec_values = IONS->at(ii).ncp_m.subvec(1,params->mesh_params.Nx)/CS->length;
							saveToHDF5(group_ionSpecies, name, &vec_values);
							#elif defined HDF5_FLOAT
							fvec_values = conv_to<fvec>::from(IONS->at(ii).ncp_m.subvec(1,params->mesh_params.Nx)/CS->length);
							saveToHDF5(group_ionSpecies, name, &fvec_values);
							#endif
							name.clear();
						}
					}
					if(params->outputs_variables.at(ov) == "Tpar_m")
					{
						if (params->mpi.IS_PARTICLES_ROOT)
						{
							//Saving ions species density
							name = "Tpar_m";
							#ifdef HDF5_DOUBLE
							vec_values = IONS->at(ii).Tpar_m.subvec(1,params->mesh_params.Nx)*CS->temperature*F_KB/F_E; // [eV]
							saveToHDF5(group_ionSpecies, name, &vec_values);
							#elif defined HDF5_FLOAT
							fvec_values = conv_to<fvec>::from(IONS->at(ii).Tpar_m.subvec(1,params->mesh_params.Nx)*CS->temperature*F_KB/F_E); // [eV]
							saveToHDF5(group_ionSpecies, name, &fvec_values);
							#endif
							name.clear();
						}
					}
					if(params->outputs_variables.at(ov) == "Tper_m")
					{
						if (params->mpi.IS_PARTICLES_ROOT)
						{
							//Saving ions species density
							name = "Tper_m";
							#ifdef HDF5_DOUBLE
							vec_values = IONS->at(ii).Tper_m.subvec(1,params->mesh_params.Nx)*CS->temperature*F_KB/F_E; // [eV]
							saveToHDF5(group_ionSpecies, name, &vec_values);
							#elif defined HDF5_FLOAT
							fvec_values = conv_to<fvec>::from(IONS->at(ii).Tper_m.subvec(1,params->mesh_params.Nx)*CS->temperature*F_KB/F_E); // [K]
							saveToHDF5(group_ionSpecies, name, &fvec_values);
							#endif
							name.clear();
						}
					}
					/*
					if(params->outputs_variables.at(ov) == "Te_m")
					{
						if (params->mpi.IS_PARTICLES_ROOT)
						{
							//Saving electron temperature values on the grid:
							name = "Te_m";
							#ifdef HDF5_DOUBLE
							vec_values = electrons->Te_m.subvec(1,params->mesh_params.Nx)*CS->temperature*F_KB/F_E; // [eV]
							saveToHDF5(group_ionSpecies, name, &vec_values);
							#elif defined HDF5_FLOAT
							fvec_values = conv_to<fvec>::from(electrons->Te_m.subvec(1,params->mesh_params.Nx)*CS->temperature*F_KB/F_E); // [eV]
							saveToHDF5(group_ionSpecies, name, &fvec_values);
							#endif
							name.clear();
						}
					}
					*/
					if(params->outputs_variables.at(ov) == "mn")
					{
						//Saving ions species density
						name = "mn";
						ivec_values = IONS->at(ii).mn;
						saveToHDF5(group_ionSpecies, name, &ivec_values);
						name.clear();

					}
					if(params->outputs_variables.at(ov) == "u_m")
					{
						if (params->mpi.IS_PARTICLES_ROOT)
						{
							Group * group_bulkVelocity = new Group( group_ionSpecies->createGroup( "u_m" ) );

							//x-component species bulk velocity
							name = "x";
							#ifdef HDF5_DOUBLE
							vec_values = CS->velocity*IONS->at(ii).nv_m.subvec(1,params->mesh_params.Nx)/IONS->at(ii).n_m.subvec(1,params->mesh_params.Nx);
							saveToHDF5(group_ionSpecies, name, &vec_values);
							#elif defined HDF5_FLOAT
							fvec_values = conv_to<fvec>::from(CS->velocity*IONS->at(ii).nv_m.subvec(1,params->mesh_params.Nx)/IONS->at(ii).n_m.subvec(1,params->mesh_params.Nx));
							saveToHDF5(group_bulkVelocity, name, &fvec_values);
							#endif
							name.clear();

							delete group_bulkVelocity;
						}
					}
				}

				delete group_ionSpecies;
			}//Iterations over the ion species.

			delete group_ions;
		}

		// Electrons
		{
			name = "electrons";
			Group * group_electrons = new Group( group_iteration->createGroup( "electrons" ) );
			name.clear();

			// Loop over all output variables:
			for(int ov=0; ov<params->outputs_variables.size(); ov++)
			{
				if(params->outputs_variables.at(ov) == "Te_m")
				{
					if (params->mpi.IS_PARTICLES_ROOT)
					{
						//Saving electron temperature values on the grid:
						name = "Te_m";
						#ifdef HDF5_DOUBLE
						vec_values = electrons->Te_m.subvec(1,params->mesh_params.Nx)*CS->temperature*F_KB/F_E; // [eV]
						saveToHDF5(group_electrons, name, &vec_values);
						#elif defined HDF5_FLOAT
						fvec_values = conv_to<fvec>::from(electrons->Te_m.subvec(1,params->mesh_params.Nx)*CS->temperature*F_KB/F_E); // [eV]
						saveToHDF5(group_electrons, name, &fvec_values);
						#endif
						name.clear();
					}
				}
			}

			delete group_electrons;
		}


	}//End of try block

  catch( FileIException error ){// catch failure caused by the H5File operations
	error.printErrorStack();
  }

  catch( DataSetIException error ){// catch failure caused by the DataSet operations
	error.printErrorStack();
  }

  catch( DataSpaceIException error ){// catch failure caused by the DataSpace operations
	error.printErrorStack();
  }
}

void HDF_TYP::saveFieldsVariables(const params_TYP * params, fields_TYP * fields, const CS_TYP * CS, const Group * group_iteration)
{
	unsigned int iIndex(params->mesh_params.Nx_PER_MPI*params->mpi.MPI_DOMAIN_NUMBER_CART+1);
	unsigned int fIndex(params->mesh_params.Nx_PER_MPI*(params->mpi.MPI_DOMAIN_NUMBER_CART+1));

	try
	{
		string name;

		int int_value;
		CPP_TYPE cpp_type_value;
		std::vector<CPP_TYPE> vector_values;

		arma::vec vec_values;
		arma::fvec fvec_values;

		arma::mat mat_values;
		arma::fmat fmat_values;

		Group * group_fields = new Group( group_iteration->createGroup( "fields" ) );//Electromagnetic fields

		for(int ov=0; ov<params->outputs_variables.size(); ov++)
		{
			if(params->outputs_variables.at(ov) == "Ex_m")
			{
				Group * group_field = new Group( group_fields->createGroup( "Ex_m" ) );//Electric fields

				//x-component of electric field
				name = "x";
				#ifdef HDF5_DOUBLE
				vec_values = CS->eField*fields->Ex_m.subvec(iIndex,fIndex);
				saveToHDF5(group_ionSpecies, name, &vec_values);
				#elif defined HDF5_FLOAT
				fvec_values = conv_to<fvec>::from( CS->eField*fields->Ex_m.subvec(iIndex,fIndex) );
				saveToHDF5(group_field, name, &fvec_values);
				#endif
				name.clear();

				delete group_field;
			}
			if(params->outputs_variables.at(ov) == "Bx_m")
			{
				Group * group_field = new Group( group_fields->createGroup( "Bx_m" ) );//Electric fields

				//x-component of magnetic field
				name = "x";
				#ifdef HDF5_DOUBLE
				vec_values = CS->bField*fields->Bx_m.subvec(iIndex,fIndex);
				saveToHDF5(group_ionSpecies, name, &vec_values);
				#elif defined HDF5_FLOAT
				fvec_values = conv_to<fvec>::from( CS->bField*fields->Bx_m.subvec(iIndex,fIndex) );
				saveToHDF5(group_field, name, &fvec_values);
				#endif
				name.clear();

				delete group_field;
			}
			if(params->outputs_variables.at(ov) == "dBx_m")
			{
				Group * group_field = new Group( group_fields->createGroup( "dBx_m" ) );//Electric fields

				name = "x";
				#ifdef HDF5_DOUBLE
				vec_values = fields->dBx_m.subvec(iIndex,fIndex)*CS->bField/CS->length;
				saveToHDF5(group_ionSpecies, name, &vec_values);
				#elif defined HDF5_FLOAT
				fvec_values = conv_to<fvec>::from( fields->dBx_m.subvec(iIndex,fIndex)*CS->bField/CS->length );
				saveToHDF5(group_field, name, &fvec_values);
				#endif
				name.clear();

				delete group_field;
			}
			if(params->outputs_variables.at(ov) == "ddBx_m")
			{
				Group * group_field = new Group( group_fields->createGroup( "ddBx_m" ) );//Electric fields

				name = "x";
				#ifdef HDF5_DOUBLE
				vec_values = fields->ddBx_m.subvec(iIndex,fIndex)*CS->bField/pow(CS->length,2);
				saveToHDF5(group_ionSpecies, name, &vec_values);
				#elif defined HDF5_FLOAT
				fvec_values = conv_to<fvec>::from( fields->ddBx_m.subvec(iIndex,fIndex)*CS->bField/pow(CS->length,2) );
				saveToHDF5(group_field, name, &fvec_values);
				#endif
				name.clear();

				delete group_field;
			}
		}

		delete group_fields;//Electromagnetic fields
	}


  catch( FileIException error ){// catch failure caused by the H5File operations
	error.printErrorStack();
  }

  catch( DataSetIException error ){// catch failure caused by the DataSet operations
	error.printErrorStack();
  }

  catch( DataSpaceIException error ){// catch failure caused by the DataSpace operations
	error.printErrorStack();
  }
}
