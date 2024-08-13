drop table profesor cascade constraint;
create table PROFESOR (nombre varchar2(40) not null,
                       dni char(8),
                       sueldo number,
                       constraint profClave primary key(dni));


drop table curso cascade constraint;
create table CURSO (nomCurso varchar2(20) not null,
                    codCurso char(3),
                    profesor char(8),
                    horas number,
                    constraint cursosClave primary key (codCurso),
                    constraint cursosAjena foreign key (profesor) references PROFESOR(dni));


drop table estudiante cascade constraint;
create table ESTUDIANTE (nombre varchar2(40) not null,
                     dni char(8),
                     fechaNac date,
		     curso char(3) not null,
                     constraint estClave primary key(dni),
		     constraint estAjena foreign key (curso) references CURSO(codCurso));

commit;
