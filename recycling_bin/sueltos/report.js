
router.post('/register', (req, res) => {
	let { diagnosisID, textDiagnosis, imageDiagnosis, dateOfDiagnosis, medicValidatorID } = req.body;
	diagnosisID = diagnosisID.trim();
	textDiagnosis = textDiagnosis.trim();
	imageDiagnosis = imageDiagnosis.trim();
	dateOfDiagnosis = dateOfDiagnosis.trim();
	medicValidatorID = medicValidatorID.trim();

	if (diagnosisID == '' || textDiagnosis == '' || dateOfDiagnosis == '') {
		res.json({
			status: 'FAILED',
			message: 'Hay campos vacíos!'
		});
	} else {
		History.find({ diagnosisID: diagnosisID })
			.then((result) => {
				if (result.length != 0) {
					res.json({
						status: 'FAILED',
						message: 'El ID del diagnóstico ya se encuentra registrado en la colección Historial!'
					});
				} else {
					newDiagnosis = new Diagnosis({
						diagnosisID,
						textDiagnosis,
						imageDiagnosis,
						dateOfDiagnosis,
						medicValidatorID
					});
					newDiagnosis
						.save()
						.then((result) => {
							res.json({
								status: 'SUCCESS',
								message: 'Diagnóstico registrado satisfactoriamente'
							});
						})
						.catch((err) => {
							res.json({
								status: 'FAILED',
								message: 'No se ha podido guardar el nuevo diagnóstico'
							});
						});
				}
			})
			.catch((err) => {
				res.json({
					status: 'FAILED',
					message:
						'se produjo un error al momento de verificar el ID del diagnóstico en la colección Historial!'
				});
			});
	}
});
