import { User } from "src/users/entities/user.entity";
import { Column, Entity, JoinColumn, OneToOne, PrimaryColumn, PrimaryGeneratedColumn } from "typeorm";

@Entity('stats')
export class Stat {
	@PrimaryColumn()
	intra_id: string;

	@OneToOne(() => User, (user) => user.stats)
	@JoinColumn({name : "intra_id"})
	user: User;

	@Column('int', {default: 0})
	win: number;

	@Column('int', {default: 0})
	lose: number;

	@Column('real', {default : 0})
	winrate: number;
}
