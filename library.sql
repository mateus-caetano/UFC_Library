CREATE TABLE IF NOT EXISTS usuarios (
    mat INTEGER NOT NULL,
    nome VARCHAR(30) NOT NULL,
    senha VARCHAR(50) NOT NULL,
    CONSTRAINT pk_mat PRIMARY KEY (mat)
);

CREATE TABLE IF NOT EXISTS livros (
    id SERIAL NOT NULL,
    titulo VARCHAR(50) NOT NULL,
    tema VARCHAR(50) NOT NULL,
    autor VARCHAR(30) NOT NULL,
    quantidade INTEGER NOT NULL,
    CONSTRAINT pk_id PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS aluguel (
    mat_usuario INTEGER NOT NULL,
    id_livro INTEGER NOT NULL,
    data_reserva TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL,

    CONSTRAINT aluguel_usuario
      FOREIGN KEY (mat_usuario)
      REFERENCES usuarios (mat)
      ON DELETE CASCADE
      ON UPDATE CASCADE,
    CONSTRAINT aluguel_livro
      FOREIGN KEY (id_livro)
      REFERENCES livros (id)
      ON DELETE CASCADE
      ON UPDATE CASCADE  
);
